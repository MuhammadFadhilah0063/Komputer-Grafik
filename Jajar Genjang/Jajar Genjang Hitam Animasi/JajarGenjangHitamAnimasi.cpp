#include <stdlib.h>
#include <gl/glut.h>

float y_pos = 0.0f; // variabel titik awal posisi Y
float x_pos = 0.0f; // variabel titik awal posisi X
float deltaY = 1.0f; // variabel perubahan posisi Y per frame
float deltaX = 1.0f; // variabel perubahan posisi X per frame
float deltaXRight = 0.02f; // variabel perubahan posisi X kekanan per frame
short a = 1;

void display() {
	glClear(GL_COLOR_BUFFER_BIT); // membersihkan layar
	glColor3f(0.0f, 0.0f, 0.0f); // memberikan warna 

	glBegin(GL_QUADS); // mulai gambar
	glVertex2f(-0.2f + x_pos, 0.2f + y_pos); // membuat titik di posisi (-0,2, 0,2)
	glVertex2f(-0.4f + x_pos, -0.2f + y_pos); // membuat titik di posisi (-0,4, -0,2)
	glVertex2f(0.2f + x_pos, -0.2f + y_pos); // membuat titik di posisi (0,2, -0,2)
	glVertex2f(0.4f + x_pos, 0.2f + y_pos); // membuat titik di posisi (0,4, 0,2)
	glEnd(); // akhir gambar

	glutSwapBuffers(); // agar opengl menampilkan titik-titik yang dibuat ke layar
}

void myinit() {
	glClearColor(1.0, 1.0, 1.0, 1.0); // membersihkan dan memberi warna baru layar (putih)
	glColor3f(0.0, 0.0, 0.0); // memberikan warna hitam
	glPointSize(2.0); // memberikan ukuran pada titik / vertex
}

void timer(int) {
	glutPostRedisplay(); // untuk memanggil function display lagi per frame
	glutTimerFunc(1000 / 60, timer, 0); // untuk menjalankan function timer agar terjadi pengulangan untuk membuat animasi bergerak (1000/60 = 1000 detik / 60 fps)

	// menggeser ke kanan
	if (a == 1)
		if (x_pos < 1.39f) {
			x_pos += deltaXRight;
		}
		else
			a = 2;

	// menggeser ke atas
	if (a == 2)
		if (y_pos < 1.19f) {
			y_pos += deltaY;
		}
		else
			a = 3;

	// menggeser ke kiri
	if (a == 3)
		if (x_pos > -1.39) {
			x_pos -= deltaX;
		}
		else
			a = 4;

	// menggeser ke bawah

	if (a == 4)
		if (y_pos > 0.01) {
			y_pos -= deltaY;
		}
		else
			a = 5;

	// menggeser ke kanan
	if (a == 5)
		if (x_pos < 0.01) {
			x_pos += deltaXRight;
		}
		else
			a = 1;
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv); // inisialisasi Glut
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // Double Buffer | Warna RGB
	glutInitWindowSize(500, 500); // Size Window 500px * 500px
	glutInitWindowPosition(0, 0); // posisi windows
	glutCreateWindow("Jajar Genjang Hitam Animasi"); // membuat window dan memberi judul
	glutDisplayFunc(display); // untuk memanggil dan menampilkan fungsi display ke window

	myinit(); // untuk memanggil function myinit

	glutTimerFunc(0, timer, 0); // untuk memanggil function timer
	glutMainLoop(); // infinity loop untuk mengulang tampilan agar opengl tetap jalan

	return 0;
};
