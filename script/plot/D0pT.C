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

const Int_t n2 = 6;
   Double_t px2[] = {2.5,3.5,4.5,5.5,7,10};
   Double_t py2[] = {18,9,4.5,2,1.1,0.46};
   Double_t ex2[] = {0.5,0.5,0.5,0.5,1,2};
   Double_t ey2[] = {0,0,0,0,0,0};
   auto gr2 = new TGraphErrors(n2,px2,py2,ex2,ey2);
   gr2->SetMarkerColor(kGreen);
   gr2->SetMarkerStyle(20);
   mg->Add(gr2);

    double ax[] = {0, 1, 2, 3, 4};
   double ay[] = {0, 2, 4, 1, 3};
   double aexl[] = {0.1, 0.2, 0.3, 0.4, 0.5};
   double aexh[] = {0.5, 0.4, 0.3, 0.2, 0.1};
   double aeyl[] = {1, 0.5, 1, 0.5, 1};
   double aeyh[] = {0.5, 1, 0.5, 1, 0.5};
   auto gae = new TGraphAsymmErrors(5, ax, ay, aexl, aexh, aeyl, aeyh);
   gr3->SetFillColor(2);
   gr3->SetFillStyle(3001);
   gr3->Draw("a2");
   gr3->Draw("p");

auto leg = new TLegend(.1,.7,.3,.9,"D^{0} in pp at 7TeV sample");
leg->SetFillColor(0);
leg->AddEntry(gr2,"Madgraph5+Pythia8");
leg->AddEntry(gr3,"LHC");

auto leg1 = new TLegend(.1,.7,.2,.5,"");
leg1->SetFillColor(0);
leg1->AddEntry(gr2,"c_{(P_{T})}>2GeV, c_{(|#eta|)}<0.5");
leg1->AddEntry(gr3,"|#eta|<0.5");

mg->DrawClone("PESame");
mg->GetXaxis()->SetTitle("P_{T} [GeV/c]");
mg->GetYaxis()->SetTitle("d#sigma/dP_{T} [#mub/GeV^{-1}c]");

leg->Draw();
leg1->Draw();
}
