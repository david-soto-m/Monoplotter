class Axis{
	public:
	double x_min,x_max,x_step,y_min,y_max,y_step;
	Axis(double x_min=-10, double x_max=10, double x_step=1,
	double y_min=-10, double y_max=10, double y_step=1);
	void validate();
	int width();
	int height();
};
