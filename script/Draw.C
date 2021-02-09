#include "TCanvas.h"
#include "TROOT.h"
#include "TGraphErrors.h"
#include "TF1.h"
#include "TLegend.h"
#include "TArrow.h"

void macro(){
const Int_t n1 = 16;
Double_t px1[] = {0.025,0.075,0.125,0.175,0.225,0.275,0.325,0.375,0.425,0.475,0.525,0.575,0.625,0.675,0.725,0.775};
Double_t py1[] = {0.002,0.0035,0.06,0.14,0.4,0.8,1.5,2.3,3.4,5.5,6.9,8.5,10.6,13.4,16.4,20.9};
Double_t ex1[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
Double_t ey1[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

TGraphErrors graph1(n1,px1,py1,ex1,ey1);

graph1.SetTitle("Measurement X(387)2 cross-section;p [GeV];cross-section[nb]");
graph1.SetMarkerStyle(kOpenCircle);
graph1.SetMarkerColor(kBlue);
graph1.SetLineColor(kBlue);
auto mycanvas = new TCanvas();
graph1.Draw("APE");

//TF1 f("Linear law","[0]+x*[1]",.5,10.5);
TF1 f("Linear law","44.3*x*x*x",0.0,5);
f.SetLineColor(kRed); f.SetLineStyle(2);
graph.Fit(&f);
f.Draw("Same");
}
int main(){
macro();
}
