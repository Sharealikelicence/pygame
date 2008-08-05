#include "pgAABBBox.h"
#include <float.h>


pgAABBBox PG_GenAABB(double left, double right, double bottom, double top)
{
	pgAABBBox box;
	box.left = left;
	box.right = right;
	box.bottom = bottom;
	box.top = top;
	return box;
}

void PG_AABBClear(pgAABBBox* box)
{
	box->left = DBL_MAX;
	box->bottom = DBL_MAX;
	box->top = -DBL_MAX;
	box->right = -DBL_MAX;
}

void PG_AABBExpandTo(pgAABBBox* box, pgVector2* p)
{
	box->left = MIN(box->left, p->real);
	box->right = MAX(box->right, p->real);
	box->bottom = MIN(box->bottom, p->imag);
	box->top = MAX(box->top, p->imag);
}

int PG_IsOverlap(pgAABBBox* boxA, pgAABBBox* boxB, double eps)
{
	double from_x, from_y, to_x, to_y;
	from_x = MAX(boxA->left, boxB->left);
	from_y = MAX(boxA->bottom, boxB->bottom);
	to_x = MIN(boxA->right, boxB->right);
	to_y = MIN(boxA->top, boxB->top);
	return from_x - eps <= to_x + eps && from_y - eps <= to_y + eps;
}

int PG_IsIn(pgVector2* p, pgAABBBox* box, double eps)
{
	return box->left - eps < p->real && p->real < box->right + eps
		&& box->bottom - eps < p->imag && p->imag < box->top + eps;
}
