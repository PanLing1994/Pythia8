#include "TCanvas.h"
#include "TROOT.h"
#include "TGraphErrors.h"
#include "TF1.h"
#include "TLegend.h"
#include "TArrow.h"
#include "TLatex.h"

void multigraph()
{
   gStyle->SetOptFit();
   auto c1 = new TCanvas("c1","multigraph");
   c1->SetLogy();

   auto mg = new TMultiGraph();

  const Int_t n1 = 10;
   Double_t px1[] = {0.5,1.5,2.5,3.5,4.5,5.5,6.5,7.5,10,12};
   Double_t py1[] = {0.22,0.44,0.38,0.25,0.14,0.071,0.036,0.02,0.0071,0.0016};
   Double_t ex1[] = {0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,2,2};
   Double_t ey1[] = {0,0,0,0,0,0,0,0,0,0};
   auto gr1 = new TGraphErrors(n1,px1,py1,ex1,ey1);
  // gr1->SetLineColor(kBlue);
   gr1->SetMarkerColor(kBlue);
   gr1->SetMarkerStyle(50);
   mg->Add(gr1);

const Int_t n2 = 10;
   Double_t px2[] = {0.5,1.5,2.5,3.5,4.5,5.5,6.5,7.5,10,12};
   Double_t py2[] = {1.57,3.13,2.71,1.78,1.00,0.51,0.26,0.14,0.05,0.011};
   Double_t ex2[] = {0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,2,2};
   Double_t ey2[] = {0,0,0,0,0,0,0,0,0,0};
   auto gr2 = new TGraphErrors(n2,px2,py2,ex2,ey2);
   gr2->SetMarkerColor(kGreen);
   gr2->SetMarkerStyle(20);
   mg->Add(gr2);

auto leg = new TLegend(.1,.7,.3,.9,"molecule structure #Sigma_{c}^{*}#bar{D}^{*}");
leg->SetFillColor(0);
leg->AddEntry(gr1,"momentum scale 0.5GeV");
leg->AddEntry(gr2,"momentum scale 1GeV");

mg->Draw("ap");
mg->GetXaxis()->SetTitle("pT [GeV]");
mg->GetYaxis()->SetTitle("d#sigma/dpT [nb/GeV]");

leg->Draw();
}
