#include "TCanvas.h"
#include "TROOT.h"
#include "TGraphErrors.h"
#include "TF1.h"
#include "TLegend.h"
#include "TArrow.h"

void macro(){
const Int_t n1 = 10;
Double_t px1[] = {0.25,0.75,1.25,1.75,2.25,2.75,3.25,3.75,4.25,4.75};
Double_t py1[] = {0.002,0.0035,0.4,0.4,2.0,3.2,4.0,6.8,11.2,16.0};
Double_t ex1[] = {.05,.1,.07,.07,.04,.05,.06,.07,.08,.05};
Double_t ey1[] = {.05,.1,.07,.07,.04,.05,.06,.07,.08,.05};

TGraphErrors graph(n1,px1,py1,ex1,ey1);

graph.SetTitle("Measurement X_3872 cross-section;p [MeV];cross-section[nb]");
graph.SetMarkerStyle(kOpenCircle);
graph.SetMarkerColor(kBlue);
graph.SetLineColor(kBlue);
auto mycanvas = new TCanvas();
graph.Draw("APE");

//TF1 f("Linear law","[0]+x*[1]",.5,10.5);
TF1 f("Linear law","0.146*x*x*x",0.0,5);
f.SetLineColor(kRed); f.SetLineStyle(2);
graph.Fit(&f);
f.Draw("Same");

}
int main(){
macro();
}
