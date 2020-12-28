#include <Windows.h>
#include <stdlib.h>
#include <gl/glut.h>

void display(void) // function display
{
    glClear(GL_COLOR_BUFFER_BIT); // membersihkan layar

    glBegin(GL_TRIANGLES); // mulai gambar dengan tipe segitiga
    glColor3f(1.0f, 0.0f, 0.0f); // memberikan warna merah
    glVertex2f(-0.4f, 0.6f); // membuat titik di posisi (-0,4,0,6)
    glColor3f(0.0f, 0.0f, 1.0f); // memberikan warna biru
    glVertex2f(-0.4f, -0.4f); // membuat titik di posisi (-0,4,-0,4)
    glColor3f(0.0f, 1.0f, 0.0f); // memberikan warna hijau
    glVertex2f(0.7f, -0.4f); // membuat titik di posisi (0,7,-0,4)
    glEnd(); // akhir gambar

    glFlush(); // agar opengl menampilkan titik-titik yang dibuat ke layar
}

int main(int argc, char* argv[]) // function main
{
    glutInit(&argc, argv); // inisialisasi Glut
    glutInitWindowSize(600, 600); // Size Window
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); // menggunakan single Buffer | Warna RGB
    glutCreateWindow("Segitiga Siku-Siku Warna"); // untuk memberi nama program di jendela window
    glutDisplayFunc(display); // untuk memanggil dan menampilkan fungsi display ke window
    glClearColor(1, 1, 1, 1); // untuk mengganti background color menjadi putih
    glutMainLoop(); // infinity loop untuk mengulang tampilan agar opengl tetap jalan
    return 0;
}
