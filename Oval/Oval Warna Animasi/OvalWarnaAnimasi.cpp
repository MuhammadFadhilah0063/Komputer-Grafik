#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

int i = 0; int j = 0;

// fungsi lingkaran
void lingkaran(int xp, int yp, int r, int n) {
    // xp merupakan parameter yang digunakan untuk menentukan titik pusat pada sumbu x dari lingkaran
    // yp merupakan parameter yang digunakan untuk menentukan titik pusat pada sumbu y dari lingkaran
    // r merupakan parameter yang digunakan untuk menentukan jari-jari dari lingkaran
    // n merupakan parameter yang digunakan untuk menentukan berapa banyak sisi yang dibutuhkan untuk membuat suatu lingkaran
    
    float a, x, y;

    glColor4ub(i, j, 0, 200); // memberikan warna ke titik

    glBegin(GL_POLYGON); // mulai gambar
    a = 6.28 / n; 

        // pengulangan titik
        for (int i = 0; i < n; i++) {
            x = xp + r * cos(i * a);
            y = yp + r * sin(i * a);
            glVertex2d(x, y);
        }
    glEnd(); // akhir gambar
}

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT); 	// membersihkan layar

    lingkaran(0, 0, 100, 25); // memanggil fungsi lingkaran
    i += 20;
    j += 1;

    glutSwapBuffers(); // agar opengl menampilkan titik-titik yang dibuat ke layar
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv); // inisialisasi Glut
    glutInitWindowSize(500, 500); // Size Window
    glutInitWindowPosition(10, 10); // mengatur posisi window 
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); // menggunakan double Buffer | Warna RGB
    glutCreateWindow("Oval Warna Animasi"); // untuk memberi nama program di jendela window
    gluOrtho2D(-600, 600, -400, 400); // untuk mengatur sistem koordinat window 

    glutDisplayFunc(display); // memanggil fungsi display
    glutIdleFunc(display);

    glClearColor(1, 1, 1, 1); // membersihkan dan memberi warna baru layar
    glutMainLoop(); // infinity loop untuk mengulang tampilan agar opengl tetap jalan
}
