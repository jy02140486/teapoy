#include "teapoyapp.h"

// Setup clanlib modules:
CL_SetupCore		setup_core;
CL_SetupDisplay		setup_display;
CL_SetupGL			setup_gl;

int main(const std::vector<CL_String> &args)
{
	TeapoyApp teapoyApp;
	teapoyApp.OnExecute();

	return 0;
}

CL_ClanApplication app(&main);


TeapoyApp::TeapoyApp()
{
	void* mp = CL_StaticMemoryPool.alloc(sizeof(CL_ConsoleWindow)*10);

	console = cl_new(sizeof(CL_ConsoleWindow),mp) CL_ConsoleWindow;




}

int TeapoyApp::drawSth(CL_GraphicContext gc)
{


	CL_Draw::line(gc, 0, 200, 640, 200, CL_Colorf::yellow);
	CL_Draw::line(gc, 200, 0, 200, 300, CL_Colorf::yellow);

	CL_String str = cl_text("abc中文经测试中文可以使用");
	//font.draw_text(gc, 100, 100, str, CL_Colorf::black);


	CL_Rect re = CL_Rect(-5,-5,5,5);
	CL_PixelBufferRef pixelBuf = gc.get_pixeldata(re);
	gc.draw_pixels(200,200,30,20, pixelBuf, CL_Colorf::red);


	CL_Vec4f red_color(1.0f, 0.0f, 0.0f, 1.0f);
	CL_Vec4f green_color(0.0f, 1.0f, 0.0f, 1.0f);

	CL_Vec2i positions[] = { CL_Vec2i(10,10), CL_Vec2i(100,100) };
	CL_Vec4f colors[] = { red_color, green_color };

	//CL_PrimitivesArray vertices(gc);
	//vertices.set_attribute(0, positions);
	//vertices.set_attribute(1, colors);

	//gc.set_program_object(cl_program_color_only);
	//gc.draw_primitives(cl_lines, 2, vertices);

	return 0;
}

int TeapoyApp::OnExecute()
{

	OnInit();

	try
	{
		while (!keyboard.get_keycode(CL_KEY_ESCAPE))
		{
			// Draw some text and lines:
			gc.clear(CL_Colorf::cadetblue);

			drawSth(gc);

			// Make the stuff visible:
			window.flip();

			// Read messages from the windowing system message queue,
			// if any are available:
			CL_KeepAlive::process();

			// Avoid using 100% CPU in the loop:
			CL_System::sleep(10);
		}
	}
	catch(CL_Exception &exception)
	{
		// Create a console window for text-output if not available

		CL_Console::write_line("Exception caught: " + exception.get_message_and_stack_trace());
		console->display_close_message();

		return -1;
	}

	return 0;
}



