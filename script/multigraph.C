/// \file
/// \ingroup tutorial_graphs
/// \notebook
/// Create and Draw a TMultiGraph.
///
/// \macro_image
/// \macro_code
///
/// \author Rene Brun


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

  const Int_t n1 = 4;
   Double_t px1[] = {11.484,14.341,16.374,22.69};
   Double_t py1[] = {0.151,0.05,0.022,0.003};
   Double_t ex1[] = {0,0,0,0};
   Double_t ey1[] = {0,0,0,0};
   auto gr1 = new TGraphErrors(n1,px1,py1,ex1,ey1);
   gr1->SetMarkerColor(kBlue);
   gr1->SetMarkerStyle(2);
   mg->Add(gr1);

const Int_t n2 = 4;
   Double_t px2[] = {11.484,14.341,16.374,22.69};
   Double_t py2[] = {0.707,0.22,0.11,0.02};
   Double_t ex2[] = {0,0,0,0};
   Double_t ey2[] = {0,0,0,0};
   auto gr2 = new TGraphErrors(n2,px2,py2,ex2,ey2);
   gr2->SetMarkerColor(kGreen);
   gr2->SetMarkerStyle(21);
   mg->Add(gr2);

  const Int_t n3 = 4;
   Double_t px3[] = {11.484,14.341,16.374,22.69};
   Double_t py3[] = {0.308,0.083,0.030,0.007};
   Double_t ex3[] = {0,0,0,0};
   Double_t ey3[] = {0,0,0,0};
   auto gr3 = new TGraphErrors(n3,px3,py3,ex3,ey3);
   gr3->SetMarkerColor(kYellow);
   gr3->SetMarkerStyle(25);
   mg->Add(gr3);

 const Int_t n4 = 4;
   Double_t px4[] = {11.484,14.341,16.374,22.69};
   Double_t py4[] = {1.9,0.56,0.20,0.048};
   Double_t ex4[] = {0,0,0,0};
   Double_t ey4[] = {0,0,0,0};
   auto gr4 = new TGraphErrors(n1,px4,py4,ex4,ey4);
   gr4->SetMarkerColor(kRed);
   gr4->SetMarkerStyle(28);
   mg->Add(gr4);

//TLegend *legend = new TLegend();
//legend->AddEntry(gr1,"CMS data");
//legend->AddEntry(gr2,"NRQCD results");
//legend->AddEntry(gr3,"momentum scale 0.5GeV");
//legend->AddEntry(gr4,"momentum scale 1GeV");
//legend->DrawClone("Same");
auto leg = new TLegend(.1,.7,.3,.9,"Lab. Lesson 1");
leg->SetFillColor(0);
leg->AddEntry(gr1,"CMS data");
leg->AddEntry(gr2,"NRQCD results");
leg->AddEntry(gr3,"momentum scale 0.5GeV");
leg->AddEntry(gr4,"momentum scale 1GeV");



mg->Draw("apl");
mg->GetXaxis()->SetTitle("pT(GeV)");
mg->GetYaxis()->SetTitle("cross-section[nb]");

leg->Draw();
//gPad->Update();
//gPad->Modified();

//c1->Modified();

   //force drawing of canvas to generate the fit TPaveStats
  // c1->Update();
//   auto stats1 = (TPaveStats*)gr1->GetListOfFunctions()->FindObject("stats");
 //  auto stats2 = (TPaveStats*)gr2->GetListOfFunctions()->FindObject("stats");
 //  auto stats3 = (TPaveStats*)gr3->GetListOfFunctions()->FindObject("stats");
 //  auto stats4 = (TPaveStats*)gr4->GetListOfFunctions()->FindObject("stats");
 //  stats1->SetTextColor(kBlue);
 //  stats2->SetTextColor(kGreen);
 //  stats3->SetTextColor(kYellow);
 //  stats4->SetTextColor(kRed);
   //stats1->SetX1NDC(0.12); stats1->SetX2NDC(0.32); stats1->SetY1NDC(0.75);
   //stats2->SetX1NDC(0.72); stats2->SetX2NDC(0.92); stats2->SetY1NDC(0.78);
}
