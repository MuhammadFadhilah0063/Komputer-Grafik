#include <Windows.h>
#include <stdlib.h>
#include <gl/glut.h>

float y_pos = 0.0f; // variabel titik awal posisi y
float delta = 0.05f; // variabel perubahan posisi per frame
bool swipe = true; // variabel untuk menggeser gambar keatas dan kebawah

void display() {
	glClear(GL_COLOR_BUFFER_BIT); // membersihkan layar
	glColor3f(1.0f, 1.0f, 1.0f); // memberikan warna 

	glBegin(GL_TRIANGLES); // mulai gambar dengan tipe segitiga
	glVertex2f(-0.3f, -0.3f + y_pos); // membuat titik di posisi (-0,3, -0,3)
	glVertex2f(0.3f, -0.3f + y_pos); // membuat titik di posisi (-0,3, -0,3)
	glVertex2f(-0.3f, 0.4f + y_pos); // membuat titik di posisi (-0,3, 0,4)
	glEnd(); // akhir gambar

	glutSwapBuffers(); // agar opengl menampilkan titik-titik yang dibuat ke layar
}

void myinit() {
	glClearColor(0.0, 0.0, 0.0, 0.0); // membersihkan dan memberi warna baru layar (putih)
	glColor3f(0.0, 0.0, 0.0); // memberikan warna hitam
	glPointSize(2.0); // memberikan ukuran pada titik / vertex
	gluOrtho2D(-1.0f, 1.0f, -1.0f, 1.0f); // untuk mengatur sistem koordinat window
}

void timer(int) {
	glutPostRedisplay(); // untuk memanggil function display lagi per frame
	glutTimerFunc(1000 / 20, timer, 0); // untuk menjalankan function timer agar terjadi pengulangan untuk membuat animasi bergerak (1000/20 = 1000 detik / 20 fps)
	if (y_pos < 0.6f && swipe)
		y_pos += delta; // agar posisi gambar berubah, posisi awal ditambah dengan perubahan per frame akan menggeser ke atas
	else
		swipe = false; // agar meghentikan pergeseran keatas
	if (y_pos > -0.7f && !swipe)
		y_pos -= delta; // agar posisi gambar berubah, posisi awal dikurang dengan perubahan per frame akan menggeser ke bawah
	else
		swipe = true; // agar meghentikan pergeseran kebawah
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv); // inisialisasi Glut
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // Double Buffer | Warna RGB
	glutInitWindowSize(500, 500); // Size Window 500px * 500px
	glutInitWindowPosition(0, 0); // posisi windows
	glutCreateWindow("Segitiga Siku-Siku Putih Animasi"); // membuat window dan memberi judul Segitiga Siku-Siku Putih Animasi
	glutDisplayFunc(display); // untuk memanggil dan menampilkan fungsi display ke window

	myinit(); // untuk memanggil function myinit

	glutTimerFunc(0, timer, 0); // untuk memanggil function timer
	glutMainLoop(); // infinity loop untuk mengulang tampilan agar opengl tetap jalan

	return 0;
};
