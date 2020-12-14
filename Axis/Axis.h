class Axis{
	private:
		double x_min,x_max,x_step,y_min,y_max,y_step;
		char discr;
		//Double to have precision to spare
	public:
		Axis(double x_min=-10, double x_max=10, double x_step=1,
		double y_min=-10, double y_max=10, double y_step=1);
		Axis(char dis,double x_min, double x_max, double x_step);
		
		double get_x_min(),get_x_max(),get_x_step();
		double get_y_min(),get_y_max(),get_y_step();
		void set_x_min(double x),set_x_max(double x),set_x_step(double x);
		void set_y_min(double y),set_y_max(double y),set_y_step(double y);
		
		void validate_x();
		void validate_y();
		void validate();
		
		int width();
		int height();
		
		bool step_on_x(int i);
		bool step_on_y(int j);
		int translator(double x, double y);
};
