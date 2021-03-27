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

  const Int_t n1 = 6;
   Double_t px1[] = {1.5,2.5,3.5,5,7};
   Double_t py1[] = {9,6.2,3.4,1.35,0.31};
   Double_t ex1[] = {0.5,0.5,0.5,1,1};
   Double_t ey1[] = {0,0,0,0,0};
   auto gr1 = new TGraphErrors(n1,px1,py1,ex1,ey1);
  // gr1->SetLineColor(kBlue);
   gr1->SetMarkerColor(kBlue);
   gr1->SetMarkerStyle(50);
   mg->Add(gr1);

const Int_t n2 = 6;
   Double_t px2[] = {1.5,2.5,3.5,5,7};
   Double_t py2[] = {110,60,27,8.8,2.0};
   Double_t ex2[] = {0.5,0.5,0.5,1,1};
   Double_t ey2[] = {30,10,4,1,0.4};
   auto gr2 = new TGraphErrors(n2,px2,py2,ex2,ey2);
   gr2->SetMarkerColor(kGreen);
   gr2->SetMarkerStyle(20);
   mg->Add(gr2);

auto leg = new TLegend(.1,.7,.3,.9,"#Lambda_{c}^{+} in pp at 7TeV sample");
leg->SetFillColor(0);
leg->AddEntry(gr1,"Madgraph5+Pythia8");
leg->AddEntry(gr2,"LHC");

auto leg1 = new TLegend(.1,.7,.2,.5,"");
leg1->SetFillColor(0);
leg1->AddEntry(gr1,"c_{(p_{T})}>2GeV, c_{(#eta)}<0.5");
leg1->AddEntry(gr2,"#eta<0.5");


mg->Draw("ap");
mg->GetXaxis()->SetTitle("p_{T} [GeV/c]");
mg->GetYaxis()->SetTitle("d#sigma/dp_{T} [#mub/GeV^{-1}c]");

leg->Draw();
leg1->Draw();


}
