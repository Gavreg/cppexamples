double clamp (double val, double min, double max)
{
		if (val < min) return min;
		if (val > max) return max;
		return val;
}

int main()
{
    double val1 = 10;
    val1 = clamp(val1, 0.0, 10.0);    
}

