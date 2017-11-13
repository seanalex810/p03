#include <iostream> 
#include<vector>
#include <string>
#include "bitmap.h" 
using namespace std; 
//checks if image has correct dimensions 
bool isValid  (Bitmap & , Bitmap &);
//show user progress of images being combined 
void progress(double ,double); 
const int MAXNUM = 10; 

int main() 
{  
string picture;
Bitmap image;
 vector < vector < vector <Pixel > > > dumb;
 vector < vector < Pixel > > smart;
for (int i=0; i < MAXNUM; i++)
  { 
    Bitmap image2;
    cout << "enter up to 10 image files. Enter done when finished. ";
    cin >> picture; 
    if (picture == "done") 
        { 
        break; 
        }
image2.open(picture); // takes the bitmap file dumb2 and assingns it to the bmp file which name is a string file
     if ( i == 0)
       {
       image = image2; 
       }
     if ( image2.isImage() && isValid ( image , image2))
        {
        vector < vector <Pixel> > dumb2;
        dumb.resize(i+1);
        dumb2 = image2.toPixelMatrix(); 
        dumb[i].resize(dumb2.size());
        smart.resize(dumb2.size());
    for(int j = 0; j < dumb2.size(); j++)
      {
        smart[j].resize(dumb2[0].size());
        dumb[i][j].resize(dumb2[0].size());
      for ( int s = 0; s < dumb2[j].size(); s++)
         {
         dumb[i][j][s] = dumb2[j][s];
         }
      }
        }
            else
             {
             i--; 
             }
    }
 for( int j = 0; j < dumb[0].size(); j++)
     {
     for ( int s = 0; s < dumb[0][j].size(); s++)
        {
         Pixel rgb;
         double r = 0;
         double g = 0;
         double b = 0;
        for( int i = 0; i< dumb.size(); i++)
          {
         rgb = dumb[i][j][s];
         r += rgb.red;
         g+= rgb.green;
         b += rgb.blue;                                
          }
         r/= dumb.size();
         g/= dumb.size();
         b/= dumb.size();
         rgb.red = r;
         rgb.green = g;
         rgb.blue = b;
         smart[j][s] = rgb;
        }
     progress (j,dumb[0].size());
        }
 Bitmap mediocre;
 mediocre.fromPixelMatrix(smart);
 mediocre.save("composite-salex.bmp");
} 
bool isValid (Bitmap & image, Bitmap & image2) 
{ 
        vector < vector <Pixel> > img= image.toPixelMatrix();
                vector < vector <Pixel> > img2 =image2.toPixelMatrix();
                for ( int i=0; i < img[0].size(); i++) 
                { 
                        if(img.size() == img2.size()) 
                        {
                                if (img[i].size() == img2[i].size() )
                                {
                                        return true; 
                                }
                                else
                                {
                                        return false;
                                }
                        } 
                        else
                        {
                                return false;
                        }
                }


}
void progress(double r, double max)
{
    cout << r<<"out of" << max << "rows are complete" << endl;  

}
