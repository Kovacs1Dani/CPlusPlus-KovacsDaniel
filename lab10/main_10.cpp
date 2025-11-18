#include <iostream>

#include "GraduationDao.h"
#include "StudentService.h"

int main() {

    GraduationDao dao(2024);

    cout << "Beiratkoztatas inditasa..." << endl;
    dao.enrollStudents("names.txt");
    cout << "Beiratkozott diakok szama: " << dao.numEnrolled() << endl;

    string subjects[] = {"roman", "matek", "magyar"};
    int numSubjects = sizeof(subjects) / sizeof(subjects[0]);

    for (int i = 0; i < numSubjects; ++i) {
        string filename = subjects[i] + ".txt";
        cout << "Jegyek beolvasasa ebbol: " << filename << " (" << subjects[i] << ")..." << endl;
        dao.readGradesSubject(subjects[i], filename);
    }

    dao.computeAverage();


    cout << "\nSikeresen vizsgazott diakok szama: " << dao.numPassed() << endl;

    cout << "\n--- Reszletes Eredmenyek (Service Teszt) ---" << endl;
    StudentServiceImpl service(&dao);

    int testIds[] = {4686, 13646, 10270};

    for (int id : testIds) {
        if (service.isEnrolled(id)) {
            cout << "Diak ID: " << id << endl;

            vector<string> subs = service.getSubjects(id);
            cout << "\tTantargyak es jegyek:" << endl;
            for (const string& sub : subs) {
                cout << "\t  - " << sub << ": " << service.getResultBySubject(id, sub) << endl;
            }

            cout << "\tAtlag: " << fixed << setprecision(2) << service.getAverage(id) << endl;
            cout << "\tSikeres erettsegi: " << (service.isPassed(id) ? "IGEN" : "NEM") << endl;
            cout << "-------------------------" << endl;
        }
    }

    return 0;
}
