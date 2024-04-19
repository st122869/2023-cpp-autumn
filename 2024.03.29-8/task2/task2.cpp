#include <iostream>
#include<fstream>

class CGraph
{
public:
    CGraph();
    CGraph(int vertexes, int edges);
    ~CGraph();
    void ReadMatrix(int vertexes, std::ifstream& stream);
    void trLights(int vertexes);

private:
    void disposeMatrix();
    void initMatrix();
    int _vertexes;
    int** _matrix;
    int _edges;
    void init();
    void dispose();
    int** _edge;
};

void CGraph::init()
{
    dispose();
    initMatrix();
}

void CGraph::dispose()
{
    disposeMatrix();
}

CGraph::CGraph()
    : _vertexes(0), _edges(0), _matrix(nullptr) {}

CGraph::CGraph(int vertexes, int edges)
    : _vertexes(vertexes), _edges(edges), _matrix(nullptr)
{
    init();
}

CGraph::~CGraph()
{
    dispose();
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

void CGraph::trLights(int vertexes)
{
    _vertexes = vertexes;
    for (int q = 1; q <= _vertexes; q++)
    {
        int sumEd = 0;
        for (int i = 0; i < _edges; ++i)
        {

            for (int j = 0; j < 2; ++j)
            {
                if (_edge[i][j] == q)
                {
                    ++sumEd;
                }
            }
        }
        std::cout << sumEd << " ";
    }

}

int main(int argc, char* argv[])
{
    std::ifstream in("task1.txt");
    CGraph edges;
    edges.ReadMatrix(5, in);

    return EXIT_SUCCESS;
}