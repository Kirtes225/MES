#pragma once

class Element {
public:
	//int ID[4];
	//walls[4]
	Node* ID;
	Element();
};

Element::Element() 
{
	ID = new Node[4];
}