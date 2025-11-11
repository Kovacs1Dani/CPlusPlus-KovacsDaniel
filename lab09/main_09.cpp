#include <iostream>

#include "Directory.h"
#include "File.h"

int main() {

    Directory root("root");

    Directory* documents = new Directory("documents");
    *documents += new File("report.txt", 1500);
    *documents += new File("notes.txt", 800);

    Directory* pictures = new Directory("pictures");
    *pictures += new File("photo1.jpg", 2048000);
    *pictures += new File("photo2.jpg", 1856000);

    //root += documents;
    //root += pictures;
    root += new File("readme.txt", 500);

    cout << "Teljes struktura:\n";
    root.display();
    cout << endl;

    cout << "Gyoker merete: " << root.getSize() << " bytes\n\n";


    string keresett = "photo1.jpg";
    fileSystemItem* found = root.find(keresett);
    if (found)
        cout << "Kereses: " << keresett << " - Talalat!\n\n";
    else
        cout << "Kereses: " << keresett << " - Nincs talalat!\n\n";


    //root -= "pictures";
    cout << "Torles utan:\n";
    root.display();
    cout << endl;

    Directory copyRoot = root;
    cout << "Masolat (copyRoot):\n";
    copyRoot.display();
    cout << endl;


    cout << "Osszehasonlitas: "
         << (File("a.txt", 1) < File("b.txt", 1) ? "a.txt < b.txt" : "b.txt < a.txt")
         << std::endl;

    return 0;
}
