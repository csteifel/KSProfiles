class windowDeleter {
	public:
		void operator()(wxWindow* window){window->Destroy();}
};

class mainApp : public wxApp {
	public:
		bool OnInit();
		int OnExit();
	private:
		std::unique_ptr<wxFrame, windowDeleter> mainWindow;
		std::thread t;
};

