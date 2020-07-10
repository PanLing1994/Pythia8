#include "Pythia8/Pythia.h"
using namespace Pythia8;

int main() {
Pythia pythia;

pythia.readFile("Pentaquark.cmnd");
pythia.init();

Event& event = pythia.event;

Hist Lambda_c_dndT("pT distribution for Lambda",9,0.,9.);
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
if (id ==  4122  )  Lambda_c_dndT.fill(event[i].pT());
else if (id ==  423) D0_star_bar_dndT.fill(event[i].pT());

}

pythia.event.list();
}

pythia.stat();

double sigma = pythia.info.sigmaGen();
cout << Lambda_c_dndT << D0_star_bar_dndT;


cout << " Cross section is " << sigma  <<endl;



HistPlot hpl("Pentaquarksplot");
hpl.frame("outtest01","8 TeV","pT distribution","nEvents");
hpl.add(Lambda_c_dndT, "h,royalblue", "Lanmda_c");
  hpl.add(D0_star_bar_dndT, "h,magenta", "D0_star_bar");
                                                                 
hpl.plot();

return 0;
}


