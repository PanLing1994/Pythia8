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

const Int_t n1 = 16;
Double_t px1[] = {0.025,0.075,0.125,0.175,0.225,0.275,0.325,0.375,0.425,0.475,0.525,0.575,0.625,0.675,0.725,0.775};
Double_t py1[] = {0.007,0.04,0.14,0.3,0.53,0.97,1.5,2.3,3.3,4.5,6.0,7.8,10.0,12.6,15.8,19.2};
Double_t ex1[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
Double_t ey1[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
TGraphErrors *gr1 = new TGraphErrors (n1,px1,py1,ex1,ey1);
gr1->Fit("pol3");
gr1->SetMarkerColor(kBlue);
gr1->SetMarkerStyle(21);
mg->Add(gr1);

const Int_t n2 = 16;
Double_t px2[] = {0.025,0.075,0.125,0.175,0.225,0.275,0.325,0.375,0.425,0.475,0.525,0.575,0.625,0.675,0.725,0.775};
Double_t py2[] = {0.00014,0.014,0.028,0.07,0.154,0.3,0.55,0.78,1.08,1.57,2.0,2.5,3.2,4.04,5.0,6.1};
Double_t ex2[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
Double_t ey2[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
TGraphErrors *gr2 = new TGraphErrors (n2,px2,py2,ex2,ey2);
gr2->Fit("pol3");
gr2->SetMarkerColor(kRed);
gr2->SetMarkerStyle(20);
mg->Add(gr2);

const Int_t n3 = 16;
Double_t px3[] = {0.025,0.075,0.125,0.175,0.225,0.275,0.325,0.375,0.425,0.475,0.525,0.575,0.625,0.675,0.725,0.775};
Double_t py3[] = {0.014,0.1,0.29,0.62,1.2,2.0,3.0,4.46,6.4,8.7,11.5,14.7,18.4,23,27.9,33.8};
Double_t ex3[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
Double_t ey3[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
TGraphErrors *gr3 = new TGraphErrors (n3,px3,py3,ex3,ey3);
gr3->Fit("pol3");
gr3->SetMarkerColor(kGreen);
gr3->SetMarkerStyle(20);
mg->Add(gr3);

const Int_t n4 = 16;
Double_t px4[] = {0.025,0.075,0.125,0.175,0.225,0.275,0.325,0.375,0.425,0.475,0.525,0.575,0.625,0.675,0.725,0.775};
Double_t py4[] = {0.007,0.028,0.07,0.175,0.35,0.68,0.96,1.33,1.86,2.7,3.63,4.5,5.7,7.0,8.4,10.3};
Double_t ex4[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
Double_t ey4[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
TGraphErrors *gr4 = new TGraphErrors (n4,px4,py4,ex4,ey4);
gr4->Fit("pol3");
gr4->SetMarkerColor(kYellow);
gr4->SetMarkerStyle(20);
mg->Add(gr4);


auto leg = new TLegend(.1,.7,.3,.9,"");
leg->SetFillColor(0);
leg->AddEntry(gr1,"#Sigma_{c}^{+}#bar{D}");
leg->AddEntry(gr2,"#Sigma_{c}^{+}#bar{D}*");
leg->AddEntry(gr3,"#Sigma_{c}^{*+}#bar{D}");
leg->AddEntry(gr4,"#Sigma_{c}^{*+}#bar{D}*");

mg->SetTitle("Measurement #Sigma_{c}#bar{D} cross-section;p [GeV];cross-section[nb]");
mg->Draw("APE");
mg->GetXaxis()->SetTitle("k [GeV]");
mg->GetYaxis()->SetTitle("cross-section [nb]");
leg->Draw();

}
int main(){
macro();
}
