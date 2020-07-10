#include "Pythia8/Pythia.h"
using namespace Pythia8;

int main() {
Pythia pythia;

pythia.readFile("X_3872.cmnd");
pythia.init();

Event& event = pythia.event;

Hist D0_dndT("pT distribution for D0",9,0.,9.);
Hist D0_star_bar_dndT("pT distribution for D0_satr_bar",9,0.,9.);

int nEvent = pythia.mode("Main:numberOfEvents");
int nAbort = pythia.mode("Main:timesAllowErrors");

int iAbort = 0;
for (int iEvent = 0; iEvent < nEvent; ++iEvent){
if (!pythia.next()){
if (++iAbort < nAbort) continue;
cout << "Event generation aborted, owing to error!\n";
break;
}

for (int i = 0; i < pythia.event.size(); ++i) {

int id = event[i].id();
if (id ==  412  )  Lambda_c_dndT.fill(event[i].pT());
else if (id ==  -423) D0_star_bar_dndT.fill(event[i].pT());

}

pythia.event.list();
}

pythia.stat();

double sigma = pythia.info.sigmaGen();
cout << D0_dndT << D0_star_bar_dndT;


cout << " Cross section is " << sigma  <<endl;



HistPlot hpl("X_3872plot");
hpl.frame("outtest02","8 TeV","pT distribution","nEvents");
hpl.add(D0_dndT, "h,royalblue", "D0");
  hpl.add(D0_star_bar_dndT, "h,magenta", "D0_star_bar");
                                                                 
hpl.plot();

return 0;
}


