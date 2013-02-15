#include <wx/wx.h>
#include <iostream>
#include <list>

//g++ 2.cpp  `wx-config --cxxflags --libs`

using namespace std;

class Point {
public:
    int x, y;
    Point(int x_pos = 0, int y_pos = 0) : x(x_pos), y(y_pos) {}
};
    
class Shape {
public:
    Point e, w, n, s;
    Point ne, nw, se, sw, c;

    virtual void draw(wxPaintDC &) = 0;
};

// int Shape::display_objects_count = 0;
// Shape *Shape::display_objects[100] = {0,};

class Window : public wxFrame
{
    list<Shape *> display_objects;
public:
    Shape *shapes;
    
    Window(const wxString& title, int x_size, int y_size);

    void OnPaint(wxPaintEvent& event);

    void add_display(Shape *s) { display_objects.push_front(s); }
};

Window::Window(const wxString& title, int x_size, int y_size)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(x_size, y_size))
{
    this->Connect(wxEVT_PAINT, wxPaintEventHandler(Window::OnPaint));
    this->Centre();

}

void Window::OnPaint(wxPaintEvent& event)
{
    wxPaintDC dc(this);
    
    list<Shape *>::iterator it;
    for (it=display_objects.begin() ; it != display_objects.end(); it++ )
    {
        (*it)->draw(dc);
    }
}


class Line : public Shape
{
public:
    Line(const wxString& title, Point start, Point end);

    // Shape method
    void draw(wxPaintDC &dc);
};

Line::Line(const wxString& title, Point start = Point(0, 0), Point end = Point(0, 0))
{

    nw = w = sw = start;
    ne = e = se = end;
    n = s = c = Point((start.x + end.x)/2, (start.y + end.y)/2);


}

void Line::draw(wxPaintDC &dc)
{
    // wxCoord x1 = 50, y1 = 60;
    // wxCoord x2 = 190, y2 = 60;

    wxCoord x1 = w.x, y1 = w.y;
    wxCoord x2 = e.x, y2 = e.y;

    dc.DrawLine(x1, y1, x2, y2);
}


class Rectangle : public Shape
{
public:
    Rectangle(const wxString &title, Point nw, Point se);

    void draw(wxPaintDC &dc);
};

Rectangle::Rectangle(const wxString &title, Point nw, Point se)
{
    this->nw = nw;
    this->se = se;
}

void Rectangle::draw(wxPaintDC &dc)
{
    wxCoord x = nw.x, y = nw.y;
    int x_size = se.x - nw.x, y_size = se.y - nw.y;

    dc.DrawRectangle(x, y, x_size, y_size);
}


class ShapeMaker {
public:
    Shape *make_line(Point s, Point e)
    { return new Line(wxT("ex"), s, e); }

};
    

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};


IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    ShapeMaker maker;

    Window *window = new Window(wxT("MainWin"), 500, 600);
    
    // Line *line = new Line(wxT("Line"));
    Shape *line = new Line(wxT("1stLine"), Point(100, 300), Point(200, 400));
    window->add_display(line);

    Shape *line2 = new Line(wxT("2Line"), Point(100, 400), Point(200, 300));
    window->add_display(line2);

    Shape *line3 = new Line(wxT("3Line"), Point(100, 300), Point(150, 250));
    window->add_display(line3);

    Shape *line4 = new Line(wxT("4Line"), Point(150, 250), Point(200, 300));
    window->add_display(line4);

    // 그냥 만들어본 팩토리
    Shape *l = maker.make_line(Point(10, 100), Point(100, 10));
    window->add_display(l);
    
    
    Shape *rec = new Rectangle(wxT("1st box"),
                               Point(100, 300), Point(200, 400));
    window->add_display(rec);
    


    window->Show(true);
    
    
    return true;
}
