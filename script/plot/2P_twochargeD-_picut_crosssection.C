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
   Double_t px1[] = {0.5,1.5,2.5,3.5,4.5,5.5,6.5,7.5,10,14};
   Double_t py1[] = {0.008,0.0085,0.0019,0.0008,0.00044,0.00019,0.0001,0.000055,0.000017,0.0000013};
   Double_t ex1[] = {0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,2,2};
   Double_t ey1[] = {0,0,0,0,0,0,0,0,0,0};
   auto gr1 = new TGraphErrors(n1,px1,py1,ex1,ey1);
  // gr1->SetLineColor(kBlue);
   gr1->SetMarkerColor(kBlue);
   gr1->SetMarkerStyle(50);
   mg->Add(gr1);

const Int_t n2 = 10;
   Double_t px2[] = {0.5,1.5,2.5,3.5,4.5,5.5,6.5,7.5,10,14};
   Double_t py2[] = {0.032,0.034,0.0076,0.0032,0.0018,0.00076,0.0004,0.00022,0.000068,0.000005};
   Double_t ex2[] = {0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,2,2};
   Double_t ey2[] = {0,0,0,0,0,0,0,0,0,0};
   auto gr2 = new TGraphErrors(n2,px2,py2,ex2,ey2);
   gr2->SetMarkerColor(kGreen);
   gr2->SetMarkerStyle(20);
   mg->Add(gr2);

const Int_t n3 = 10;
   Double_t px3[] = {0.5,1.5,2.5,3.5,4.5,5.5,6.5,7.5,10,14};
   Double_t py3[] = {0.37,0.39,0.087,0.037,0.02,0.0087,0.0047,0.0025,0.00087,0.00006};
   Double_t ex3[] = {0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,2,2};
   Double_t ey3[] = {0,0,0,0,0,0,0,0,0,0};
   auto gr3 = new TGraphErrors(n3,px3,py3,ex3,ey3);
   gr3->SetMarkerColor(kRed);
   gr3->SetMarkerStyle(80);
   mg->Add(gr3);


auto leg = new TLegend(.1,.7,.3,.9,"molecule structure #Sigma_{c}^{++}D*^{-}");
leg->SetFillColor(0);
leg->AddEntry(gr1,"0.5m_{#pi}");
leg->AddEntry(gr2,"m_{#pi}");
leg->AddEntry(gr3,"2m_{#pi}");

mg->Draw("ap");
mg->GetXaxis()->SetTitle("pT [GeV]");
mg->GetYaxis()->SetTitle("#sigma [nb]");

leg->Draw();
}
