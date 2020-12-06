class Axis{
	private:
		double x_min,x_max,x_step,y_min,y_max,y_step;//Double to have precision to spare
	public:
		Axis(double x_min=-10, double x_max=10, double x_step=1,
		double y_min=-10, double y_max=10, double y_step=1);
		
		void validate();
		int width();
		int height();
		
		bool step_x(int i);
		bool step_y(int j);
		int translator(double x, double y);
		
		double get_x_min(),get_x_max(),get_x_step();
		double get_y_min(),get_y_max(),get_y_step();
};
