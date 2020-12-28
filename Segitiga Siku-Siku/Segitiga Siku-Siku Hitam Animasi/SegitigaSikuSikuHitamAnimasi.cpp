#include <Windows.h>
#include <stdlib.h>
#include <gl/glut.h>

float x_pos = 0.0f; // variabel titik awal posisi x
float delta = 0.025f; // variabel perubahan posisi per frame
bool swipe = true; // variabel untuk menggeser gambar kekiri dan kekanan

void display() {
	glClear(GL_COLOR_BUFFER_BIT); // membersihkan layar
	glColor3f(0.0f, 0.0f, 0.0f); // memberikan warna 

	glBegin(GL_TRIANGLES); // mulai gambar dengan tipe segitiga
	glVertex2f(-0.3f + x_pos, -0.3f); // membuat titik di posisi (-0,3, -0,3)
	glVertex2f(0.3f + x_pos, -0.3f); // membuat titik di posisi (-0,3, -0,3)
	glVertex2f(-0.3f + x_pos, 0.4f); // membuat titik di posisi (-0,3, 0,4)
	glEnd(); // akhir gambar

	glutSwapBuffers(); // agar opengl menampilkan titik-titik yang dibuat ke layar
}

void myinit() {
	glClearColor(1.0, 1.0, 1.0, 1.0); // membersihkan dan memberi warna baru layar (putih)
	glColor3f(0.0, 0.0, 0.0); // memberikan warna hitam
	glPointSize(2.0); // memberikan ukuran pada titik / vertex
	gluOrtho2D(-1.0f, 1.0f, -1.0f, 1.0f); // untuk mengatur sistem koordinat window
}

void timer(int) {
	glutPostRedisplay(); // untuk memanggil function display lagi per frame
	glutTimerFunc(1000/30, timer, 0); // untuk menjalankan function timer agar terjadi pengulangan untuk membuat animasi bergerak (1000/30 = 1000 detik / 30 fps)
	if (x_pos < 0.69f && swipe) 
		x_pos += delta; // agar posisi gambar berubah, posisi awal ditambah dengan perubahan per frame akan menggeser ke kanan
	else
		swipe = false; // agar meghentikan pergeseran kekanan
	if (x_pos > -0.69f && !swipe)
		x_pos -= delta; // agar posisi gambar berubah, posisi awal dikurang dengan perubahan per frame akan menggeser ke kiri
	else
		swipe = true; // agar meghentikan pergeseran kekiri
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv); // inisialisasi Glut
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // Double Buffer | Warna RGB
	glutInitWindowSize(500, 500); // Size Window 500px * 500px
	glutInitWindowPosition(0, 0); // posisi windows
	glutCreateWindow("Segitiga Siku-Siku Hitam Animasi"); // membuat window dan memberi judul Segitiga Siku-Siku Hitam Animasi
	glutDisplayFunc(display); // untuk memanggil dan menampilkan fungsi display ke window

	myinit(); // untuk memanggil function myinit

	glutTimerFunc(0, timer, 0); // untuk memanggil function timer
	glutMainLoop(); // infinity loop untuk mengulang tampilan agar opengl tetap jalan

	return 0;
};
