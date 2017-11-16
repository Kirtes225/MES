#pragma once

class Node {
public:
	double x, y, t;
	int status;
	Node(double, double, double, int);
	Node();
};

Node::Node()
{

}

Node::Node(double x, double y, double t, int status)
{
	this->x = x;
	this->y = y;
	this->t = t;
	this->status = status;
}