#include <iostream>
void my_int_func(int x)
{
    printf( "%d\n", x );
}

float relu(float f)
{
	return f;
}

class Layer
{
	public:
		Layer(int x, float (*func)(float f)) : size(x)
		{
			activation = func;
		}
		float try_func(float f)
		{
			return activation(f);
		}

	private:
		int size;
		float (*activation)(float input);

}; 
 
int main()
{
    void (*foo)(int);
    foo = &my_int_func;
 
    /* call my_int_func (note that you do not need to write (*foo)(2) ) */
    foo( 2 );
    /* but if you want to, you may */
    (*foo)( 2 );
 
	Layer layer(1, &relu);
	std::cout << layer.try_func(12) << std::endl;
    return 0;
}
