#include <ruby.h>

void simple_sum() {
	VALUE two, three, sum;
	two = INT2NUM(2);
	three = INT2NUM(3);
	sum = rb_funcall(two, rb_intern("+"), 1, three);

	// printf("%d\n", NUM2INT(sum));
	rb_funcall(Qnil, rb_intern("puts"), 1, sum);
}

void simple_area() {
	VALUE pi, radius, area, r_sq;

	radius = DBL2NUM(5.0);
	rb_define_const(rb_mMath, "PI_SM", DBL2NUM(3.14));
	pi = rb_const_get_from(rb_mMath, rb_intern("PI_SM"));
	// rb_funcall(Qnil, rb_intern("puts"), 1, pi);
	r_sq = rb_funcall(radius, rb_intern("*"), 1, radius);
	
	area = rb_funcall(pi, rb_intern("*"), 1, r_sq);
	rb_funcall(Qnil, rb_intern("puts"), 1, area);
}

// rb_define_method needs a C function to call
VALUE calculate(VALUE self, VALUE radius) {
	VALUE pi, r_sq, area;

	rb_define_const(rb_mMath, "PI_SM", DBL2NUM(3.14));
	pi = rb_const_get_from(rb_mMath, rb_intern("PI_SM"));
	r_sq = rb_funcall(radius, rb_intern("*"), 1, radius);

	area = rb_funcall(pi, rb_intern("*"), 1, r_sq);
	return area;
}

void module_class_area() {
	VALUE mArea, cCircle, radius, obj, area;

	radius = DBL2NUM(5.0);

	mArea = rb_define_module("Area");
	cCircle = rb_define_class_under(mArea, "Circle", rb_cObject);

	rb_define_method(cCircle, "calculate", calculate, 1);

	obj = rb_funcall(cCircle, rb_intern("new"), 0);
	area = rb_funcall(obj, rb_intern("calculate"), 1, radius);

	rb_funcall(Qnil, rb_intern("puts"), 1, area);
}

int main(int argc, char* argv[])
{
	// Init VM
	ruby_init();

	module_class_area();

	// destroy VM
	return ruby_cleanup(0);
}


