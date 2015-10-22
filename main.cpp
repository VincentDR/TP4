#include "trianglewindow.h"
#include "filemanager.h"
#include "ply.h"

int main(int argc, char **argv)
{



    srand(time(NULL));
    QGuiApplication app(argc, argv);

    QSurfaceFormat format;
    format.setSamples(16);

    paramCamera* c=new paramCamera();
    FileManager fm = FileManager();

    int nbFenetres = 4;
    TriangleWindow** windows;
    windows = (TriangleWindow**) malloc(sizeof(TriangleWindow*) * nbFenetres);
    int posX = 0;
    int posY = 0;
    bool changX = true;

    bool chargement = false;

    switch(chargement){
    case false:
        for(int i =0; i < nbFenetres; i++){
            Ply* poly = new Ply("autumntree.ply");
            poly->setTaille(0.025);
            poly->setPosX(0);poly->setPosY(0);poly->setPosZ(0);
            poly->setRotX(45);poly->setRotY(0);poly->setRotZ(0);


            Ply* poly2 = new Ply("autumntree.ply");
            poly2->setTaille(0.025);
            poly2->setPosX(-5);poly2->setPosY(0);poly2->setPosZ(0);
            poly2->setRotX(0);poly2->setRotY(0);poly2->setRotZ(0);

            Ply* poly3 = new Ply("autumntree.ply");
            poly3->setTaille(0.025);
            poly3->setPosX(5);poly3->setPosY(0);poly3->setPosZ(0);
            poly3->setRotX(0);poly3->setRotY(0);poly3->setRotZ(0);

            if(i == 0){//serveur
                windows[i] =  new TriangleWindow();
            }else{
                windows[i] = new TriangleWindow(20);
            }
            windows[i]->c = c;
            windows[i]->setFormat(format);
            windows[i]->resize(500,375);
            if(changX){
                changX = !changX;
                windows[i]->setPosition(posX, posY);
                posX += 500;
            }else{
                changX = !changX;
                windows[i]->setPosition(posX, posY);
                posY += 375;
                posX = 0;
            }

            windows[i]->addPolygone(poly);
            windows[i]->addPolygone(poly2);
            windows[i]->addPolygone(poly3);
            windows[i]->setSeason(i%4, false);
            windows[i]->show();
        }


        fm.saveCustomMap("Test.txt", windows,nbFenetres);
        break;
    case true:
        TriangleWindow** tw = fm.loadCustomMap("Test.txt");
        for(int i = 0; i < fm.getNbFenetres(); i++){
            tw[i]->setFormat(format);
            tw[i]->resize(500,375);
            if(changX){
                changX = !changX;
                tw[i]->setPosition(posX, posY);
                posX += 500;
            }else{
                changX = !changX;
                tw[i]->setPosition(posX, posY);
                posY += 375;
                posX = 0;
            }
            tw[i]->show();
        }
        break;
    }







    return app.exec();
}
