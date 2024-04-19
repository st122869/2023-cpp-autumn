#include <iostream>
#include<fstream>
#include<algorithm>

struct SEdge {
    int a;
    int b;
    int w;
    SEdge(int a = 0, int b = 0) : a(a), b(b) {}
    SEdge(const SEdge& src) : a(src.a), b(src.b) {}
    ~SEdge() {}
    void set(int a, int b)
    {
        this->a = a;
        this->b = b;
    }
    friend std::ostream& operator<<(std::ostream& stream, const SEdge& edge);
};

class CGraph
{
public:
    CGraph();
    CGraph(int vertexes, int edges);
    ~CGraph();
    void ReadMatrix(int vertexes, std::ifstream& stream);
    int getEdgesCountFromMatrix();
    void countEdges();
    void list(int vertexes);
    void ReadEdges(int edges, std::ifstream& in);
    void initEdges();
    int* _listOfVertexes;

private:
    void disposeMatrix();
    void initMatrix();
    int _vertexes;
    int _edges;
    int** _matrix;
    int** _edge;
    void init();
    void dispose();
};

void CGraph::dispose()
{
    disposeMatrix();
}

CGraph::CGraph()
    : _vertexes(0), _matrix(nullptr) {}

CGraph::CGraph(int vertexes, int edges)
    : _vertexes(vertexes), _matrix(nullptr)
{
    init();
}

CGraph::~CGraph()
{
    dispose();
}

void CGraph::list(int vertexes)
{
    _vertexes = vertexes;
    for (int i = 1; i <= 2; i++)
    {
        int count = 0;
        for (int j = 1; j <= _edges; j++)
        {
            if (_edge[j][1] == _edge[i][1])
            {
                ++count;
            }
        }
        std::cout << count << " ";

        if (count != 0)
        {
            if (count == 1)
            {
                for (int k = 1; k <= _edges; k++)
                {
                    if (_edge[k][1] == _edge[i][1])
                    {
                        std::cout << _edge[k][1];
                    }
                }

            }
            else
            {
                _listOfVertexes = new int[count] { 0 };
                int index = 0;
                for (int m = 1; m <= _edges; m++)
                {
                    if (_edge[m][1] == _edge[i][1])
                    {
                        _listOfVertexes[index] = _edge[m][1];
                        ++index;
                    }
                }

                std::sort(_listOfVertexes, _listOfVertexes + count);

                for (int f = 0; f < count; f++)
                {
                    std::cout << _listOfVertexes[f] << " ";
                }
                std::cout << std::endl;
            }
        }
        std::cout << std::endl;
    }

}

void CGraph::ReadMatrix(int vertexes, std::ifstream& in)
{
    _vertexes = vertexes;
    initMatrix();
    for (int i = 0; i < _vertexes; ++i)
    {
        for (int j = 0; j < _vertexes; ++j)
        {
            in >> _matrix[i][j];
        }
    }
}

void CGraph::ReadEdges(int edges, std::ifstream& in)
{
    _edges = edges;
    initEdges();
    for (int i = 1; i <= _edges; ++i)
    {
        for (int j = 1; j <= 2; ++j)
        {
            in >> _edge[i][j];
        }
    }
}

void CGraph::initEdges()
{
    if (_edges == 0)
    {
        return;
    }

    _edge = new int* [_edges];
    for (int i = 1; i <= _edges; i++)
    {
        _edge[i] = new int[2] { 0 };
    }
}

void CGraph::disposeMatrix()
{
    if (_matrix != nullptr)
    {
        for (int i = 0; i < _vertexes; ++i)
        {
            delete[] _matrix[i];
        }
        delete[] _matrix;
        _matrix = nullptr;
    }
}

void CGraph::initMatrix()
{
    if (_vertexes == 0)
    {
        return;
    }
    _matrix = new int* [_vertexes];
    for (int i = 0; i < _vertexes; ++i)
    {
        _matrix[i] = new int[_vertexes] { 0 };
    }
}

int CGraph::getEdgesCountFromMatrix()
{
    int count = 0;
    for (int i = 0; i < _vertexes; ++i)
    {
        for (int j = 0; j < _vertexes; ++j)
        {
            count += (_matrix[i][j] != 0);
        }
    }
    return count / 2;
}

void CGraph::countEdges()
{
    std::cout << getEdgesCountFromMatrix() << std::endl;
}

std::ostream& operator<<(std::ostream& stream, const SEdge& edge)
{
    stream << edge.a << " " << edge.b;
    return stream;
}

int main(int argc, char* argv[])
{
    std::cout << 4 << std::endl;
    std::ifstream in("task8.1.txt");

    CGraph list;
    list.ReadEdges(6, in);
    list.list(4);

    return EXIT_SUCCESS;
}