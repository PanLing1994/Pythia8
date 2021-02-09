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
Double_t py1[] = {0.00,0.0035,0.02,0.1,0.1,0.2,0.3,0.5,1.0,1.3,2.1,2.3,2.9,3.4,4.4,5.2};
Double_t ex1[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
Double_t ey1[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
TGraphErrors *gr1 = new TGraphErrors (n1,px1,py1,ex1,ey1);
gr1->SetMarkerColor(kBlue);
gr1->SetMarkerStyle(21);
mg->Add(gr1);




const Int_t n2 = 16;
Double_t px2[] = {0.025,0.075,0.125,0.175,0.225,0.275,0.325,0.375,0.425,0.475,0.525,0.575,0.625,0.675,0.725,0.775};
Double_t py2[] = {0.00,0.0174,0.00874,0.00874,0.0874,0.00175,0.026,0.03,0.135,0.81,0.81,1.22,1.485,2.03,2.57,3.51};
Double_t ex2[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
Double_t ey2[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
TGraphErrors *gr2 = new TGraphErrors (n2,px2,py2,ex2,ey2);
gr2->SetMarkerColor(kRed);
gr2->SetMarkerStyle(20);
mg->Add(gr2);

mg->SetTitle("Measurement #Sigma_{c}*#bar{D}* cross-section;p [GeV];cross-section[nb]");
mg->Draw("APE");
mg->GetXaxis()->SetTitle("k [GeV]");
mg->GetYaxis()->SetTitle("cross-section [nb]");

}
int main(){
macro();
}
