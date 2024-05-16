#pragma once
#include <iostream>

namespace project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBoxDimension;
	protected:
	private: System::Windows::Forms::Panel^ panel1;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel2;


	private: System::Windows::Forms::Button^ res_button;

	private: int** matrix;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label2;





	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->textBoxDimension = (gcnew System::Windows::Forms::TextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->res_button = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBoxDimension
			// 
			this->textBoxDimension->Location = System::Drawing::Point(383, 20);
			this->textBoxDimension->Name = L"textBoxDimension";
			this->textBoxDimension->Size = System::Drawing::Size(100, 26);
			this->textBoxDimension->TabIndex = 0;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::LavenderBlush;
			this->panel1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->panel1->Location = System::Drawing::Point(23, 160);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(576, 483);
			this->panel1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(535, 8);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(156, 63);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Изменить размерность";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label1->Location = System::Drawing::Point(31, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(337, 20);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Введите размерность матрицы смежности";
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::LavenderBlush;
			this->panel2->Location = System::Drawing::Point(628, 160);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(571, 483);
			this->panel2->TabIndex = 4;
			// 
			// res_button
			// 
			this->res_button->Location = System::Drawing::Point(535, 77);
			this->res_button->Name = L"res_button";
			this->res_button->Size = System::Drawing::Size(156, 61);
			this->res_button->TabIndex = 5;
			this->res_button->Text = L"Результат";
			this->res_button->UseVisualStyleBackColor = true;
			this->res_button->Click += gcnew System::EventHandler(this, &MyForm::res_button_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Алгоритм Дейкстры", L"Алгоритм Флойда-Уоршелла" });
			this->comboBox1->Location = System::Drawing::Point(227, 80);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(256, 28);
			this->comboBox1->TabIndex = 6;
			this->comboBox1->Text = L"Алгоритм Дейкстры";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(31, 83);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(144, 20);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Выбор алгоритма";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Pink;
			this->ClientSize = System::Drawing::Size(1223, 804);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->res_button);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->textBoxDimension);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"Алгоритмы Дейкстры и Флойда-Уоршелла";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: array<TextBox^, 2>^ _matrix;

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		int a = 0;
		String^ str = textBoxDimension->Text;
		if (str->Length == 0)
		{
			MessageBox::Show(this, "Введите размерность", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else
		{
			for (int i = 0; i < str->Length; i++)
			{
				if (!Char::IsDigit(str[i]))
				{
					a++;
				}
			}
			if (a != 0)
			{
				MessageBox::Show(this, "Проверьте правильность введённой размерности", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			else
			{
				panel1->Controls->Clear();

				int dimension = System::Convert::ToInt32(textBoxDimension->Text);

				_matrix = gcnew array<TextBox^, 2>(dimension, dimension);

				for (int i = 0; i < dimension; i++)
				{
					for (int j = 0; j < dimension; j++)
					{
						TextBox^ textBox = gcnew TextBox();
						textBox->Location = System::Drawing::Point(30 * i, 30 * j);
						textBox->Size = System::Drawing::Size(30, 30);
						textBox->Name = "textBox_" + i + "_" + j;
						panel1->Controls->Add(textBox);
						_matrix[i, j] = textBox;
					}
				}
			}
		}
	}

	private: System::Void dijkstra(int startVertex, int vertexes, int** matrix, int dist[])
	{
		bool* visited = new bool[vertexes];

		for (int i = 0; i < vertexes; i++)
		{
			dist[i] = INT_MAX;
			visited[i] = false;
		}

		dist[startVertex] = 0;

		for (int count = 0; count < vertexes - 1; count++)
		{
			int minDist = INT_MAX;
			int minIndex = 0;

			for (int i = 0; i < vertexes; i++)
			{
				if (!visited[i] && dist[i] <= minDist)
				{
					minDist = dist[i];
					minIndex = i;
				}
			}

			int u = minIndex;
			visited[u] = true;

			for (int i = 0; i < vertexes; i++)
			{
				if (!visited[i] && matrix[u][i] != 0 && dist[u] != INT_MAX && dist[u] + matrix[u][i] < dist[i])
				{
					dist[i] = dist[u] + matrix[u][i];
				}
			}
		}

		delete[] visited;
	}


	private: System::Void floydWarshall(int vertexes, int** _matrix, int** res, int& h)
	{

		for (int i = 0; i < vertexes; i++)
		{
			for (int j = 0; j < vertexes; j++)
			{
				res[i][j] = _matrix[i][j];
			}
		}

		for (int k = 0; k < vertexes; k++)
		{
			for (int i = 0; i < vertexes; i++)
			{
				for (int j = 0; j < vertexes; j++)
				{
					if (res[i][k] != INT_MAX && res[k][j] != INT_MAX && res[i][k] + res[k][j] < res[i][j])
					{
						res[i][j] = res[i][k] + res[k][j];
					}
				}
			}
		}

		for (int i = 0; i < vertexes; i++)
		{
			if (res[i][i] < 0)
			{
				++h;
			}
		}
	}

	private: System::Void res_button_Click(System::Object^ sender, System::EventArgs^ e)
	{
		char a = 0;
		int b = 0;
		int n = 0;
		int check = 0;
		int d = 0;
		int vertexes = System::Convert::ToInt32(textBoxDimension->Text);

		int** matrix = new int* [vertexes];
		for (int i = 0; i < vertexes; i++)
		{
			matrix[i] = new int[vertexes];
		}

		for (int i = 0; i < vertexes; i++)
		{
			for (int j = 0; j < vertexes; j++)
			{
				String^ cellText = _matrix[i, j]->Text;
				if (cellText == "INF")
				{
					matrix[i][j] = INT_MAX;
				}
				else if (cellText->Length == 0)
				{
					n++;
				}
				else
				{
					for (int i = 0; i < cellText->Length; i++)
					{
						if ((!Char::IsDigit(cellText[i]) && (cellText[i] != '-')))
						{
							a++;
						}
					}
					if (a != 0)
					{
						b++;
					}
					else
					{
						int value = System::Convert::ToInt32(cellText);
						matrix[i][j] = value;
						if (value < 0)
						{
							check++;
						}
					}
				}
			}
		}

		if (b != 0)
		{
			MessageBox::Show(this, "Проверьте правильность введённых весов", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

		if (n != 0)
		{
			MessageBox::Show(this, "Введите все веса", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

		if (comboBox1->SelectedItem == "Алгоритм Флойда-Уоршелла" && n == 0 && a == 0)
		{
			panel2->Controls->Clear();

			int** res = new int* [vertexes];
			for (int i = 0; i < vertexes; i++)
			{
				res[i] = new int[vertexes];
				for (int j = 0; j < vertexes; j++)
				{
					res[i][j] = 0;
				}
			}
			int h = 0;
			floydWarshall(vertexes, matrix, res, h);

			if (h != 0)
			{
				MessageBox::Show(this, "Отрицательные циклы", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			else
			{

				for (int i = 0; i < vertexes; i++)
				{
					for (int j = 0; j < vertexes; j++)
					{
						String^ str1 = "";
						if (res[i][j] == INT_MAX)
						{
							str1 = "INF";
						}
						else
						{
							str1 = res[i][j].ToString();
						}
						TextBox^ textBox = gcnew TextBox();
						textBox->Location = System::Drawing::Point(30 * i, 30 * j);
						textBox->Size = System::Drawing::Size(30, 30);
						panel2->Controls->Add(textBox);
						textBox->Text = str1;
					}
				}
			}

			for (int i = 0; i < vertexes; i++)
			{
				delete[] res[i];
			}
			delete[] res;
		}
		else if (comboBox1->SelectedItem == "Алгоритм Дейкстры" && n == 0 && a == 0)
		{
			if (check != 0)
			{
				MessageBox::Show(this, "Введены отрицательные веса", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}

			else
			{
				panel2->Controls->Clear();

				int* dist = new int[vertexes];

				dijkstra(0, vertexes, matrix, dist);

				String^ output = "";
				for (int i = 0; i < vertexes; i++)
				{
					String^ str2 = "";
					if (dist[i] == INT_MAX)
					{
						str2 = "INF";
					}
					else
					{
						str2 = dist[i].ToString();
					}
					output += str2 + " ";
				}

				TextBox^ textBox = gcnew TextBox();
				textBox->Location = System::Drawing::Point(30, 30);
				textBox->Size = System::Drawing::Size(100, 50);
				panel2->Controls->Add(textBox);
				textBox->Text = output;

				delete[] dist;
			}
		}

		for (int i = 0; i < vertexes; i++)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
	}

	};
}
