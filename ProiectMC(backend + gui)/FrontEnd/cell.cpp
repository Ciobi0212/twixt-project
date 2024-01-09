#include "cell.h";
using namespace twixt;


Cell::Cell() {
	m_peg = nullptr;
	m_links = std::unordered_set<Link*>();
	m_color = Color::NONE;
}

Cell::~Cell() = default;

Color Cell::getColor() const {
	return m_color;
}

Peg& Cell::getPeg() const {
	if (m_peg)
		return *m_peg;
	else
		throw std::exception("Cell has no peg");
}

std::unordered_set<Link*> twixt::Cell::getLinks() const
{
	return m_links;
}

void Cell::setColor(Color color) {
	m_color = color;
}

void twixt::Cell::setPositionOnScreen(QPoint position)
{
	m_positionOnScreen = position;
}

QPoint twixt::Cell::getPositionOnScreen() const
{
	return m_positionOnScreen;
}

void Cell::setPeg(Peg* peg) {
	m_peg = peg;
}

void twixt::Cell::addLink(Link* link)
{
	m_links.insert(link);
}

void twixt::Cell::removeLink(Link* link)
{
	m_links.erase(link);
}

bool Cell::hasColor() const {
	if (m_color == Color::NONE) {
		return false;
	}
	
	return true;
}

bool Cell::hasPeg() const {
	if (m_peg == nullptr) {
		return false;
	}

	return true;
}

bool twixt::Cell::hasLinks() const
{
	if (m_links.size() == 0){
		return false;
	}

	return true;
}

