#include <stdlib.h>
#include <gl/glut.h>

void display(void) // function display
{
    glClear(GL_COLOR_BUFFER_BIT); // membersihkan layar
    glColor3f(0.0f, 0.0f, 0.0f); // memberikan warna 

    glBegin(GL_QUADS); // mulai gambar
    glVertex2f(-0.1f, 0.2f); // membuat titik di posisi (-0,1, 0,2)
    glVertex2f(-0.3f, -0.2f); // membuat titik di posisi (-0,3, -0,2)
    glVertex2f(0.3f, -0.2f); // membuat titik di posisi (0,3, -0,2)
    glVertex2f(0.5f, 0.2f); // membuat titik di posisi (0,5, 0,2)
    glEnd(); // akhir gambar

    glFlush(); // agar opengl menampilkan titik-titik yang dibuat ke layar
}

int main(int argc, char* argv[]) // function main
{
    glutInit(&argc, argv); // inisialisasi Glut
    glutInitWindowSize(600, 600); // Size Window
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); // menggunakan single Buffer | Warna RGB
    glutCreateWindow("Jajar Genjang Hitam"); // untuk memberi nama program di jendela window
    glutDisplayFunc(display); // untuk memanggil dan menampilkan fungsi display ke window
    glClearColor(1, 1, 1, 1); // untuk mengganti background color menjadi putih
    glutMainLoop(); // infinity loop untuk mengulang tampilan agar opengl tetap jalan
    return 0;
}
