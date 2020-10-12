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
   Double_t py1[] = {0.211,0.081,0.039,0.0068};
   Double_t ex1[] = {0,0,0,0};
   Double_t ey1[] = {0,0,0,0};
   auto gr1 = new TGraphErrors(n1,px1,py1,ex1,ey1);
  // gr1->SetLineColor(kBlue);
   gr1->SetMarkerColor(kBlue);
   gr1->SetMarkerStyle(50);
   mg->Add(gr1);

const Int_t n2 = 4;
   Double_t px2[] = {11.484,14.341,16.374,22.69};
   Double_t py2[] = {0.707,0.22,0.11,0.02};
   Double_t ex2[] = {0,0,0,0};
   Double_t ey2[] = {0,0,0,0};
   auto gr2 = new TGraphErrors(n2,px2,py2,ex2,ey2);
   //gr2->SetLineColor(kGreen);
   gr2->SetMarkerColor(kGreen);
   gr2->SetMarkerStyle(20);
   mg->Add(gr2);

  const Int_t n3 = 4;
   Double_t px3[] = {11.484,14.341,16.374,22.69};
   Double_t py3[] = {0.0816,0.0288,0.0159,0.0023};
   Double_t ex3[] = {0,0,0,0};
   Double_t ey3[] = {0.031,0.011,0.006,0.00087};
   auto gr3 = new TGraphErrors(n3,px3,py3,ex3,ey3);
   //gr3->SetLineColor(kYellow);
   gr3->SetMarkerColor(kYellow);
   gr3->SetMarkerStyle(30);
   mg->Add(gr3);

//TF1 f("Linear law","0.146*x**x*x",0.0,5);
//f.SetLineColor(kRed); f.SetLineStyle(2);
//gr3->Fit(&f);
//f.Draw("Same");


 const Int_t n4 = 4;
   Double_t px4[] = {11.484,14.341,16.374,22.69};
   Double_t py4[] = {0.60,0.216,0.120,0.017};
   Double_t ex4[] = {0,0,0,0};
   Double_t ey4[] = {0.228,0.082,0.045,0.0065};
   auto gr4 = new TGraphErrors(n1,px4,py4,ex4,ey4);
   //gr4->SetLineColor(kRed);
   gr4->SetMarkerColor(kRed);
   gr4->SetMarkerStyle(40);
   mg->Add(gr4);

//TLegend *legend = new TLegend();
//legend->AddEntry(gr1,"CMS data");
//legend->AddEntry(gr2,"NRQCD results");
//legend->AddEntry(gr3,"momentum scale 0.5GeV");
//legend->AddEntry(gr4,"momentum scale 1GeV");
//legend->DrawClone("Same");
auto leg = new TLegend(.1,.7,.3,.9,"cross-section");
leg->SetFillColor(0);
leg->AddEntry(gr1,"CMS data");
leg->AddEntry(gr2,"NRQCD results");
leg->AddEntry(gr3,"momentum scale 0.5GeV");
leg->AddEntry(gr4,"momentum scale 1GeV");



mg->Draw("apl");
mg->GetXaxis()->SetTitle("pT [GeV]");
mg->GetYaxis()->SetTitle("d#sigma/dpT [nb/GeV]");

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
