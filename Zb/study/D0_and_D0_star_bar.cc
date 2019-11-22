#include "Pythia8/Pythia.h"
#include "Pythia8/Analysis.h"
#include "Pythia8/Basics.h"
using namespace Pythia8;
int main() {
  Pythia pythia;
 // pythia.readString("Beams:eCM = 8000.");
 // pythia.readString("HardQCD:all = on");
 // pythia.readString("PhaseSpace:pTHatMin = 20.");
pythia.readFile("X_3872.cnmd");
pythia.init();

Event& event = pythia.event;

Hist D0_dndT("pT distribution for D0",100,0.,10.);
Hist D0_star_bar_dndT("pT distribution for D0_satr_bar",100,0.,10.);
Hist nFinal("final particle multiplicity", 100, -0.5, 1599.5);
Hist nCharged("charged particle multiplicity", 100, -0.5, 799.5);
Hist pThard("process pT scale", 100, 0., 500.);

int nEvent = pythia.mode("Main:numberOfEvents");
int nAbort = pythia.mode("Main:timesAllowErrors");

//if error else break
int iAbort = 0;
for (int iEvent = 0; iEvent < nEvent; ++iEvent){
if (!pythia.next()){
if (++iAbort < nAbort) continue;
cout << "Event generation aborted, owing to error!\n";
break;
}

pThard.fill( pythia.info.pTHat() );

for (int i = 0;i < event.size();++i) {
int nFin = 0;
int nChg = 0;


if (event[i].isFinal()) nFin++;
if (event[i].isCharged()) ++nChg;

nFinal.fill( nFin );
nCharged.fill( nChg );


int id = event[i].id();
      if (id ==  421)  D0_dndT.fill(event[i].pT());
      else if (id ==  -423) D0_star_bar_dndT.fill(event[i].pT());
}
}

pythia.event.list();

pythia.stat();
 nFinal   *= 1. / (16. * nEvent);
  nCharged *= 1. / (8. * nEvent);

  D0_dndT    *= 10. / nEvent;
  D0_star_bar_dndT    *= 10. / nEvent;
cout << nFinal << nCharged << D0_dndT << D0_star_bar_dndT;
//python name teste01plot.py
 HistPlot hpl("test01plot");

 hpl.frame("", "Total and charged particle multiplicities",
    "$n$", "$\\mathrm{d}P/\\mathrm{d}n$");
  hpl.add( nFinal, "h,royalblue", "total multiplicity");
  hpl.add( nCharged, "h,orange", "only charged");
  hpl.plot();
// HistPlot::plotFrame( string frameName, const Hist& hist, string title = "", string xLabel = "", string yLabel = "", string style = "h", string legend = "void", bool logY = false)  
//HistPlot::frame( string frameName, string title = "", string xLabel = "", string yLabel = "")  

hpl.frame("outtest","8 TeV","pT distribution","nEvents");
//HistPlot::add(const Hist& hist, string style = "h", string legend = "void")  
  hpl.add(D0_dndT, "h,royalblue", "D0");
  hpl.add(D0_star_bar_dndT, "h,magenta", "D0_star_bar");
hpl.plot();
return 0;
}

