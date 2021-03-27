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

const Int_t n1 = 6;
Double_t px1[] = {0.0125,0.0375,0.0625,0.0875,0.125,0.15};
Double_t py1[] = {0.0001,0.001,0.003,0.006,0.01,0.021};
Double_t ex1[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
Double_t ey1[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
TGraphErrors *gr1 = new TGraphErrors (n1,px1,py1,ex1,ey1);
gr1->SetMarkerColor(kBlue);
gr1->SetMarkerStyle(21);
mg->Add(gr1);

const Int_t n2 = 6;
Double_t px2[] = {0.0125,0.0375,0.0625,0.0875,0.125,0.15};
Double_t py2[] = {0.0,0.0001,0.0006,0.0017,0.0023,0.006};

Double_t ex2[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
Double_t ey2[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
TGraphErrors *gr2 = new TGraphErrors (n2,px2,py2,ex2,ey2);
gr2->SetMarkerColor(kRed);
gr2->SetMarkerStyle(20);
mg->Add(gr2);

const Int_t n3 = 6;
Double_t px3[] = {0.0125,0.0375,0.0625,0.0875,0.125,0.15};
Double_t py3[] = {0.0,0.00001,0.000052,0.00001,0.0008,0.002};

Double_t ex3[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
Double_t ey3[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
TGraphErrors *gr3 = new TGraphErrors (n3,px3,py3,ex3,ey3);
gr3->SetMarkerColor(kGreen);
gr3->SetMarkerStyle(20);
mg->Add(gr3);

auto leg = new TLegend(.1,.7,.3,.9,"#Sigma_{c}^{++}D^{-}");
leg->SetFillColor(0);
leg->AddEntry(gr1,"0 <  pT < 1 [GeV/c]");
leg->AddEntry(gr2,"1 < pT < 2 [GeV/c]");
leg->AddEntry(gr3,"2 < pT < 3 [GeV/c]");

mg->SetTitle("P_{c} cross-section of different p_{T} bins");
mg->Draw("APE");
mg->GetXaxis()->SetTitle("k [GeV/c]");
mg->GetYaxis()->SetTitle("cross-section [nb]");
leg->Draw();

}
int main(){
macro();
}
