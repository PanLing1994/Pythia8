#include "Riostream.h"
void basic() {
// read file tree/basic.dat
   TString dir = gROOT->GetTutorialDir();
   dir.Append("/tree/");
   dir.ReplaceAll("/./","/");
   ifstream in;
   in.open(Form("%spT.txt",dir.Data()));

   Float_t x;
   Int_t nlines = 0;
   auto f = TFile::Open("basic.root","RECREATE");
   TH1F h1("h1","x_3872 monmentum distribution",20,0,300);

   while (1) {
      in >> x ;
      if (!in.good()) break;
      h1.Fill(x);
      nlines++;
   }
   printf(" found %d points\n",nlines);

   in.close();

   f->Write();
}
