#pragma once

class Node {
public:
	double x, y, t;
	int status;
	Node(double, double);
	Node();
};

Node::Node()
{

}

Node::Node(double x, double y)
{
	this->x = x;
	this->y = y;
}