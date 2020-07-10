ivoid basic() {

TCanvas *c1 = new TCanvas("c1");
c1->SetLogy();
c1->SetGrid();

h1->GetYaxis()->SetTitle("nEvents");
h1->GetXaxis()->SetTitle("pT(GeV)");
h1->Draw("e");


const Int_t n1 =6 ;
Double_t px1[] = {2.5,3.5,4.5,5.5,7.0,10.0};
Double_t py1[] = {120,40,19.5,9,9,4.8};
Double_t ex1[] = {.05,.1,.07,.07,.04,.05,.06,.07,.08,.05};
Double_t ey1[] = {.8,.7,.6,.5,.4,.4,.5,.6,.7,.8};
TGraphErrors *gr1 = new TGraphErrors(n1,px1,py1,ex1,ey1);
gr1->Draw("same");


/*
gr1->SetMarkerColor(kBlue);
gr1->SetFillColor(kYellow);
gr1->SetMarkerStyle(21);
gr1->DrawClone("E3AL");

mg->Add(gr1);
mg->Add(h1);

TLegend leg(.1,.7,.3,.9,"Hadron Group");
leg->SetFillColor(0);
leg->AddEntry(&gr1,"ALICE");
leg->AddEntry(&h1,"PYTHIA");
leg->DrawClone("Same");

mg->Draw("apl");
/*

/*
TMultiGraph *mg = new TMultiGraph();
mg->GetXaxis()->SetTitle("X values");
mg->GetYaxis()->SetTitle("Y values");

TMultiGraph *mg = new TMultiGraph();
const int n1=10;
Double_t px1[] = {-0.1, 0.05, 0.25, 0.35, 0.5, 0.61,0.7,0.85,0.89,0.95};
Double_t py1[] = {-1,2.9,5.6,7.4,9,9.6,8.7,6.3,4.5,1};
Double_t ex1[] = {.05,.1,.07,.07,.04,.05,.06,.07,.08,.05};
Double_t ey1[] = {.8,.7,.6,.5,.4,.4,.5,.6,.7,.8};
TGraphErrors *gr1 = new TGraphErrors(n1,px1,py1,ex1,ey1);
gr1->SetMarkerColor(kBlue);
gr1->SetMarkerStyle(21);
mg->Add(gr1);
mg->Draw("apl");
*/
c1->SaveAs(“D0.gif”);

}






















