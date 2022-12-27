long long maxArea(long long A[], int len)
{
	int l = 0;      // left wall of container
	int r = len -1; // right wall of container
	long long area = 0;

	while (l < r)
	{
		// Calculating the max area
		area = max(area, min(A[l], A[r]) * (r - l));

        // maximise height of container
		if (A[l] < A[r])
			l += 1;
		else
			r -= 1;
	}
	return area;
}
