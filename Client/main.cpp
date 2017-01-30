#include <FL/Fl.H>
#include "ConnectWindow.h"

int main(int argc, char* argv[]) {
	Fl::args(argc, argv);
	Fl::get_system_colors();
	Fl::visual(FL_RGB);

	SL::Remote_Access_Library::ConnectWindow c;
	Fl::lock();
	while (Fl::wait() > 0) {
		if (Fl::thread_message()) {

		}
	}
	return 0;
}