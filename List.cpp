#include "List.h"


List::List(std::ifstream& file)
{
	TInfo elem;
	auto comp = [this](TInfo t1, TInfo t2)->bool
		{
			return t1.count_twos() < t2.count_twos();
		};
	auto Find_Place = [this, comp](TInfo elem)->ptrNODE
		{
			ptrNODE res = head;
			while (res->next && comp(res->next->info, elem))
				res = res->next;
			return res;
		};
	while (file >> elem)
	{
		if (empty() || comp(head->info, elem) )
			add_to_head(elem);
		else
			add_by_ptr(Find_Place(elem)->next, elem);
	}
}

void List::add_by_ptr(ptrNODE& ptr, TInfo elem)
{
	ptr = new NODE(elem, ptr);

}

void List::add_to_head(TInfo elem)
{
	head = new NODE(elem, head);
}

void List::add_to_tail(TInfo elem)
{
	if (!head)
		head = new NODE(elem, head);
	else
	{
		ptrNODE tmp = head;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		add_by_ptr(tmp->next, elem);
	}
}




void List::del_by_ptr(ptrNODE& ptr)
{
	if (ptr && ptr->next)
	{
		ptrNODE tmp = ptr->next;
		ptr->next = ptr->next->next;
		delete tmp;
	}
}

void List::del_from_head()
{
	if (head)
	{
		ptrNODE tmp = head;
		head = head->next;
		delete tmp;
	}
}



void List::print(std::ostream& stream, const char* message) const
{
	stream << message;
	ptrNODE tmp{ head };
	while (tmp)
	{
		stream << tmp->info << '\n';
		tmp = tmp->next;

	}
	stream << '\n';
}

bool List::empty()
{
	return head == nullptr;
}

void List::clear()
{
	while (!empty())
		del_from_head();
}


List::List(const List& other)
{
	std::cout << "����������� �����������\n";
	ptrNODE tmp = other.head;
	this->head = nullptr;
	while (tmp)
	{
		this->add_to_tail(tmp->info);
		tmp = tmp->next;
	}
}


List& List::operator=(const List& other)
{
	if (this != &other)
	{
		std::cout << "�������� �����������\n";
		this->clear();
		ptrNODE ptr = other.head;
		while (ptr)
		{
			this->add_to_tail(ptr->info);
			ptr = ptr->next;
		}

	}
	return *this;
}

List::List(List&& tmp) :head(tmp.head)
{
	std::cout << "����������� �����������\n";
	tmp.head = nullptr;
}

List& List::operator=(List&& tmp)
{
	std::cout << "�������� �����������\n";
	if (this != &tmp)
	{
		this->clear();
		this->head = tmp.head;
		tmp.head = nullptr;
	}
	return *this;
}




