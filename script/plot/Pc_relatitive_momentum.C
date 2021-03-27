#include "TCanvas.h"
#include "TROOT.h"
#include "TGraphErrors.h"
#include "TF1.h"
#include "TLegend.h"
#include "TArrow.h"

void macro(){

TCanvas *c1 = new TCanvas("c1","multigraph",700,500);
c1->SetGrid();
TMultiGraph *mg = new TMultiGraph();

const Int_t n1 = 30;
Double_t px1[] = {0.025,0.075,0.125,0.175,0.225,0.275,0.325,0.375,0.425,0.475,0.525,0.575,0.625,0.675,0.725,0.775,0.825,0.875,0.925,0.975,1.025,1.075,1.125,1.175,1.225,1.275,1.325,1.375,1.425,1.475};
Double_t py1[] = {0.001,0.007,0.021,0.098,0.266,0.5,0.75,1.07,1.53,2.23,2.93,3.86,4.81,6.0,7.1,8.54,10.0,11.8,13.7,15.6,17.7,19.8,21.9,23.7,25.4,27,28.5,30.1,31.7,33};
Double_t ex1[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
Double_t ey1[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
TGraphErrors *gr1 = new TGraphErrors (n1,px1,py1,ex1,ey1);
gr1->SetMarkerColor(kBlue);
gr1->SetMarkerStyle(21);
mg->Add(gr1);

const Int_t n2 = 30;
Double_t px2[] = {0.025,0.075,0.125,0.175,0.225,0.275,0.325,0.375,0.425,0.475,0.525,0.575,0.625,0.675,0.725,0.775,0.825,0.875,0.925,0.975,1.025,1.075,1.125,1.175,1.225,1.275,1.325,1.375,1.425,1.475};
Double_t py2[] = {0.0001,0.004,0.014,0.056,0.084,0.147,0.27,0.42,0.54,0.74,0.97,1.3,1.66,2.2,2.8,3.3,3.9,4.7,5.57,6.7,8.0,9.5,11.6,13.9,16.45,19.5,22.7,26.2,30.2,34.3};
Double_t ex2[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
Double_t ey2[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
TGraphErrors *gr2 = new TGraphErrors (n2,px2,py2,ex2,ey2);
gr2->SetMarkerColor(kRed);
gr2->SetMarkerStyle(20);
mg->Add(gr2);

const Int_t n3 = 30;
Double_t px3[] = {0.025,0.075,0.125,0.175,0.225,0.275,0.325,0.375,0.425,0.475,0.525,0.575,0.625,0.675,0.725,0.775,0.825,0.875,0.925,0.975,1.025,1.075,1.125,1.175,1.225,1.275,1.325,1.375,1.425,1.475};
Double_t py3[] = {0.00005,0.0001,0.007,0.014,0.028,0.07,0.112,0.175,0.196,0.26,0.34,0.49,0.6,0.74,0.97,1.11,1.36,1.54,1.77,2.1,2.5,3.0,3.5,4.1,4.6,5.3,6.2,7.15,8.2,9.1};
Double_t ex3[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
Double_t ey3[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
TGraphErrors *gr3 = new TGraphErrors (n3,px3,py3,ex3,ey3);
gr3->SetMarkerColor(kGreen);
gr3->SetMarkerStyle(20);
mg->Add(gr3);

auto leg = new TLegend(.1,.7,.3,.9,"#Sigma_{c}^{++}D^{-}");
leg->SetFillColor(0);
leg->AddEntry(gr1,"0 < pT < 1 [GeV/c]");
leg->AddEntry(gr2,"1 < pT < 2 [GeV/c]");
leg->AddEntry(gr3,"2 < pT < 3 [GeV/c]");

mg->SetTitle("P_{c} cross-section of different p_{T} bins");
mg->Draw("APE");
mg->GetXaxis()->SetTitle("k [GeV/c]");
mg->GetYaxis()->SetTitle("#sigma [nb]");

leg->Draw();

}
int main(){
macro();
}
