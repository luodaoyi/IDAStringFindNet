#pragma once

#include <msclr\lock.h>
#include <vcclr.h>
#include <bytes.hpp>
#include <ida.hpp>
#include <idp.hpp>
#include <loader.hpp>
#include "FindEa.h"
#include "StrCmp.h"
#include <Windows.h>

namespace StringFindNet {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Text;
	using namespace System::Threading::Tasks;
	using namespace msclr;

	using namespace System::Runtime::InteropServices; // DllImportAttribute类所在的命名空间
	[DllImportAttribute("user32.dll", CharSet = CharSet::Auto)] 
	extern "C" int SetWindowPos(IntPtr hWnd, int hWndInsertAfter, int x, int y, int Width, int Height, int flags);
	/// <summary>
	/// FindStr 摘要
	/// </summary>
	public ref class FindStr : public System::Windows::Forms::Form
	{
	public:
		FindStr(void)
		{
			InitializeComponent();
			//
			//TODO:  在此处添加构造函数代码
			//
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~FindStr()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::RichTextBox^  richTextBox1;
	protected:
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ListView^  listView1;
	private: System::Windows::Forms::ColumnHeader^  columnHeader1;
	private: System::Windows::Forms::ColumnHeader^  columnHeader2;
	private: System::Windows::Forms::ColumnHeader^  columnHeader3;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  复制地址ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  添加到注释ToolStripMenuItem;
	public: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ProgressBar^  progressBar1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip2;
	private: System::Windows::Forms::ToolStripMenuItem^  MenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  MenuItem2;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button3;
	public: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label4;
	public: System::Windows::Forms::CheckBox^  checkBox3;
	private: System::Windows::Forms::ColumnHeader^  columnHeader4;
	private: System::Windows::Forms::CheckBox^  chkios;
	private: System::Windows::Forms::ColumnHeader^  columnHeader5;
	private: System::Windows::Forms::ToolStripMenuItem^  复制内容ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  复制十六进制ToolStripMenuItem;
	private: System::Windows::Forms::CheckBox^  chktop;
	private: System::Windows::Forms::CheckBox^  chkfind;
	private: System::Windows::Forms::CheckBox^  chkHexFind;
	private: System::Windows::Forms::ToolStripMenuItem^  转十六进制ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  转UnicodeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  unicodeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ansiToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  unicodeToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  uTF8ToolStripMenuItem;
	private: System::Windows::Forms::CheckBox^  checkBox4;
	private: System::Windows::Forms::ToolStripMenuItem^  ansi去掉前两位ToolStripMenuItem;
	public: 
	private: 
	public: 
	private: 
	private: System::ComponentModel::IContainer^  components;






	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>
		

#pragma region Windows Form Designer generated code

		/// <summary>
		/// 设计器支持所需的方法 - 不要
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->contextMenuStrip2 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->MenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->MenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->转十六进制ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->转UnicodeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader4 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader5 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->复制地址ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->添加到注释ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->复制内容ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->复制十六进制ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->unicodeToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->unicodeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ansiToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->uTF8ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->chkios = (gcnew System::Windows::Forms::CheckBox());
			this->chktop = (gcnew System::Windows::Forms::CheckBox());
			this->chkfind = (gcnew System::Windows::Forms::CheckBox());
			this->chkHexFind = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->ansi去掉前两位ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->contextMenuStrip2->SuspendLayout();
			this->contextMenuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// richTextBox1
			// 
			this->richTextBox1->ContextMenuStrip = this->contextMenuStrip2;
			this->richTextBox1->Location = System::Drawing::Point(12, 29);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(373, 67);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			this->richTextBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &FindStr::richTextBox1_MouseDown);
			// 
			// contextMenuStrip2
			// 
			this->contextMenuStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->MenuItem1, 
				this->MenuItem2, this->转十六进制ToolStripMenuItem, this->转UnicodeToolStripMenuItem});
			this->contextMenuStrip2->Name = L"contextMenuStrip2";
			this->contextMenuStrip2->Size = System::Drawing::Size(137, 92);
			// 
			// MenuItem1
			// 
			this->MenuItem1->Name = L"MenuItem1";
			this->MenuItem1->Size = System::Drawing::Size(136, 22);
			this->MenuItem1->Text = L"复制(&C)";
			this->MenuItem1->Click += gcnew System::EventHandler(this, &FindStr::MenuItem1_Click);
			// 
			// MenuItem2
			// 
			this->MenuItem2->Name = L"MenuItem2";
			this->MenuItem2->Size = System::Drawing::Size(136, 22);
			this->MenuItem2->Text = L"粘贴(&V)";
			this->MenuItem2->Click += gcnew System::EventHandler(this, &FindStr::MenuItem2_Click);
			// 
			// 转十六进制ToolStripMenuItem
			// 
			this->转十六进制ToolStripMenuItem->Name = L"转十六进制ToolStripMenuItem";
			this->转十六进制ToolStripMenuItem->Size = System::Drawing::Size(136, 22);
			this->转十六进制ToolStripMenuItem->Text = L"转十六进制";
			this->转十六进制ToolStripMenuItem->Click += gcnew System::EventHandler(this, &FindStr::转十六进制ToolStripMenuItem_Click);
			// 
			// 转UnicodeToolStripMenuItem
			// 
			this->转UnicodeToolStripMenuItem->Name = L"转UnicodeToolStripMenuItem";
			this->转UnicodeToolStripMenuItem->Size = System::Drawing::Size(136, 22);
			this->转UnicodeToolStripMenuItem->Text = L"转Unicode";
			this->转UnicodeToolStripMenuItem->Click += gcnew System::EventHandler(this, &FindStr::转UnicodeToolStripMenuItem_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(391, 51);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(63, 30);
			this->button1->TabIndex = 1;
			this->button1->Text = L"查找";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &FindStr::button1_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(88, 6);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(297, 20);
			this->comboBox1->TabIndex = 2;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &FindStr::comboBox1_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(71, 12);
			this->label1->TabIndex = 3;
			this->label1->Text = L"请选择编码:";
			// 
			// listView1
			// 
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(5) {this->columnHeader1, this->columnHeader4, 
				this->columnHeader2, this->columnHeader5, this->columnHeader3});
			this->listView1->ContextMenuStrip = this->contextMenuStrip1;
			this->listView1->FullRowSelect = true;
			this->listView1->GridLines = true;
			this->listView1->Location = System::Drawing::Point(12, 170);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(442, 400);
			this->listView1->TabIndex = 4;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
			this->listView1->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &FindStr::listView1_MouseDoubleClick);
			// 
			// columnHeader1
			// 
			this->columnHeader1->Text = L"地址";
			this->columnHeader1->Width = 81;
			// 
			// columnHeader4
			// 
			this->columnHeader4->Text = L"长度";
			// 
			// columnHeader2
			// 
			this->columnHeader2->Text = L"内容";
			this->columnHeader2->Width = 215;
			// 
			// columnHeader5
			// 
			this->columnHeader5->Text = L"十六进制";
			// 
			// columnHeader3
			// 
			this->columnHeader3->Text = L"被引用";
			this->columnHeader3->Width = 82;
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(9) {this->复制地址ToolStripMenuItem, 
				this->添加到注释ToolStripMenuItem, this->复制内容ToolStripMenuItem, this->复制十六进制ToolStripMenuItem, this->unicodeToolStripMenuItem1, this->unicodeToolStripMenuItem, 
				this->ansiToolStripMenuItem, this->uTF8ToolStripMenuItem, this->ansi去掉前两位ToolStripMenuItem});
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(193, 224);
			// 
			// 复制地址ToolStripMenuItem
			// 
			this->复制地址ToolStripMenuItem->Name = L"复制地址ToolStripMenuItem";
			this->复制地址ToolStripMenuItem->Size = System::Drawing::Size(192, 22);
			this->复制地址ToolStripMenuItem->Text = L"复制地址";
			this->复制地址ToolStripMenuItem->Click += gcnew System::EventHandler(this, &FindStr::复制地址ToolStripMenuItem_Click);
			// 
			// 添加到注释ToolStripMenuItem
			// 
			this->添加到注释ToolStripMenuItem->Name = L"添加到注释ToolStripMenuItem";
			this->添加到注释ToolStripMenuItem->Size = System::Drawing::Size(192, 22);
			this->添加到注释ToolStripMenuItem->Text = L"添加到注释";
			this->添加到注释ToolStripMenuItem->Click += gcnew System::EventHandler(this, &FindStr::添加到注释ToolStripMenuItem_Click);
			// 
			// 复制内容ToolStripMenuItem
			// 
			this->复制内容ToolStripMenuItem->Name = L"复制内容ToolStripMenuItem";
			this->复制内容ToolStripMenuItem->Size = System::Drawing::Size(192, 22);
			this->复制内容ToolStripMenuItem->Text = L"复制内容";
			this->复制内容ToolStripMenuItem->Click += gcnew System::EventHandler(this, &FindStr::复制内容ToolStripMenuItem_Click);
			// 
			// 复制十六进制ToolStripMenuItem
			// 
			this->复制十六进制ToolStripMenuItem->Name = L"复制十六进制ToolStripMenuItem";
			this->复制十六进制ToolStripMenuItem->Size = System::Drawing::Size(192, 22);
			this->复制十六进制ToolStripMenuItem->Text = L"复制十六进制";
			this->复制十六进制ToolStripMenuItem->Click += gcnew System::EventHandler(this, &FindStr::复制十六进制ToolStripMenuItem_Click);
			// 
			// unicodeToolStripMenuItem1
			// 
			this->unicodeToolStripMenuItem1->Name = L"unicodeToolStripMenuItem1";
			this->unicodeToolStripMenuItem1->Size = System::Drawing::Size(192, 22);
			this->unicodeToolStripMenuItem1->Text = L"Unicode";
			this->unicodeToolStripMenuItem1->Click += gcnew System::EventHandler(this, &FindStr::unicodeToolStripMenuItem1_Click);
			// 
			// unicodeToolStripMenuItem
			// 
			this->unicodeToolStripMenuItem->Name = L"unicodeToolStripMenuItem";
			this->unicodeToolStripMenuItem->Size = System::Drawing::Size(192, 22);
			this->unicodeToolStripMenuItem->Text = L"Unicode(去掉首字符)";
			this->unicodeToolStripMenuItem->Click += gcnew System::EventHandler(this, &FindStr::unicodeToolStripMenuItem_Click);
			// 
			// ansiToolStripMenuItem
			// 
			this->ansiToolStripMenuItem->Name = L"ansiToolStripMenuItem";
			this->ansiToolStripMenuItem->Size = System::Drawing::Size(192, 22);
			this->ansiToolStripMenuItem->Text = L"Ansi";
			this->ansiToolStripMenuItem->Click += gcnew System::EventHandler(this, &FindStr::ansiToolStripMenuItem_Click);
			// 
			// uTF8ToolStripMenuItem
			// 
			this->uTF8ToolStripMenuItem->Name = L"uTF8ToolStripMenuItem";
			this->uTF8ToolStripMenuItem->Size = System::Drawing::Size(192, 22);
			this->uTF8ToolStripMenuItem->Text = L"UTF8";
			this->uTF8ToolStripMenuItem->Click += gcnew System::EventHandler(this, &FindStr::uTF8ToolStripMenuItem_Click);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(391, 10);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(42, 16);
			this->checkBox1->TabIndex = 5;
			this->checkBox1->Text = L"ALL";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(10, 593);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(53, 12);
			this->label2->TabIndex = 6;
			this->label2->Text = L"准备就绪";
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(12, 576);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(428, 11);
			this->progressBar1->TabIndex = 7;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(335, 590);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 12);
			this->label3->TabIndex = 8;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(391, 87);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(63, 30);
			this->button2->TabIndex = 9;
			this->button2->Text = L"查找所有";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &FindStr::button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 125);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(251, 21);
			this->textBox1->TabIndex = 10;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(327, 120);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(63, 26);
			this->button3->TabIndex = 9;
			this->button3->Text = L"搜索";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &FindStr::button3_Click);
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(235, 103);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(66, 16);
			this->checkBox2->TabIndex = 11;
			this->checkBox2->Text = L"Unicode";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(391, 120);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(63, 26);
			this->button4->TabIndex = 9;
			this->button4->Text = L"下一个";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &FindStr::button4_Click);
			// 
			// textBox2
			// 
			this->textBox2->ImeMode = System::Windows::Forms::ImeMode::Disable;
			this->textBox2->Location = System::Drawing::Point(161, 100);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(66, 21);
			this->textBox2->TabIndex = 10;
			this->textBox2->Text = L"4";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(90, 103);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(71, 12);
			this->label4->TabIndex = 3;
			this->label4->Text = L"字符串长度:";
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(307, 103);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(48, 16);
			this->checkBox3->TabIndex = 11;
			this->checkBox3->Text = L"Utf8";
			this->checkBox3->UseVisualStyleBackColor = true;
			// 
			// chkios
			// 
			this->chkios->AutoSize = true;
			this->chkios->Checked = true;
			this->chkios->CheckState = System::Windows::Forms::CheckState::Checked;
			this->chkios->Location = System::Drawing::Point(12, 101);
			this->chkios->Name = L"chkios";
			this->chkios->Size = System::Drawing::Size(72, 16);
			this->chkios->TabIndex = 12;
			this->chkios->Text = L"检测中文";
			this->chkios->UseVisualStyleBackColor = true;
			// 
			// chktop
			// 
			this->chktop->AutoSize = true;
			this->chktop->Location = System::Drawing::Point(391, 29);
			this->chktop->Name = L"chktop";
			this->chktop->Size = System::Drawing::Size(48, 16);
			this->chktop->TabIndex = 13;
			this->chktop->Text = L"置顶";
			this->chktop->UseVisualStyleBackColor = true;
			this->chktop->CheckedChanged += gcnew System::EventHandler(this, &FindStr::chktop_CheckedChanged);
			// 
			// chkfind
			// 
			this->chkfind->AutoSize = true;
			this->chkfind->Location = System::Drawing::Point(269, 126);
			this->chkfind->Name = L"chkfind";
			this->chkfind->Size = System::Drawing::Size(48, 16);
			this->chkfind->TabIndex = 14;
			this->chkfind->Text = L"慢速";
			this->chkfind->UseVisualStyleBackColor = true;
			// 
			// chkHexFind
			// 
			this->chkHexFind->AutoSize = true;
			this->chkHexFind->Location = System::Drawing::Point(270, 145);
			this->chkHexFind->Name = L"chkHexFind";
			this->chkHexFind->Size = System::Drawing::Size(72, 16);
			this->chkHexFind->TabIndex = 15;
			this->chkHexFind->Text = L"十六进制";
			this->chkHexFind->UseVisualStyleBackColor = true;
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->Checked = true;
			this->checkBox4->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox4->Location = System::Drawing::Point(15, 148);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(54, 16);
			this->checkBox4->TabIndex = 16;
			this->checkBox4->Text = L"检测0";
			this->checkBox4->UseVisualStyleBackColor = true;
			// 
			// ansi去掉前两位ToolStripMenuItem
			// 
			this->ansi去掉前两位ToolStripMenuItem->Name = L"ansi去掉前两位ToolStripMenuItem";
			this->ansi去掉前两位ToolStripMenuItem->Size = System::Drawing::Size(192, 22);
			this->ansi去掉前两位ToolStripMenuItem->Text = L"Ansi(去掉前两位)";
			this->ansi去掉前两位ToolStripMenuItem->Click += gcnew System::EventHandler(this, &FindStr::ansi去掉前两位ToolStripMenuItem_Click);
			// 
			// FindStr
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(457, 612);
			this->Controls->Add(this->checkBox4);
			this->Controls->Add(this->chkHexFind);
			this->Controls->Add(this->chkfind);
			this->Controls->Add(this->chktop);
			this->Controls->Add(this->chkios);
			this->Controls->Add(this->checkBox3);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->listView1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->richTextBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"FindStr";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"查找字符---由软件逆向及开发研究所 QQ群:60149022 提供";
			this->Load += gcnew System::EventHandler(this, &FindStr::FindStr_Load);
			this->contextMenuStrip2->ResumeLayout(false);
			this->contextMenuStrip1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}


	public: Encoding^ Code;
	public: Encoding^ CodeUnicode;

	public: bool IsFind;
	public:int mlstindex;

	public:int mThreadID;
	public:ea_t mminaddress ;
	public:ea_t mmaxaddress ;
	public:int mlstcount;
	public:array<FindEa^,2>^mfindea;
	
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

				 if (!IsFind)
				 {
					 if (String::IsNullOrEmpty(richTextBox1->Text))
					 {
						 MessageBox::Show("请输入字符串");
						 return;
					 }
					 IsFind = true;
					 this->button1->Text = "停止";

					 this->listView1->Items->Clear();
					 this->progressBar1->Maximum = inf.maxEA-inf.minEA;
					 this->progressBar1->Value = 0;

					 Threading::ThreadPool::QueueUserWorkItem(gcnew Threading::WaitCallback(FindStrRun), this);

				 }
				 else
				 {
					 IsFind = false;
					 this->button1->Text = "查找";

				 }


	}

	private: static Void FindStrRun(Object^ send)
	{
				 try
				 {
					 FindStr^ win = dynamic_cast<FindStr^>(send);

					 if (win != nullptr)
					 {

						 array<unsigned char> ^StrBytes;
						 if(win->checkBox3->Checked)
							 StrBytes = win->Code->UTF8->GetBytes(win->richTextBox1->Text);
						 else if (win->checkBox2->Checked)
							 StrBytes = win->Code->Unicode->GetBytes(win->richTextBox1->Text);
						 else
							StrBytes = win->Code->GetBytes(win->richTextBox1->Text);

						 cli::pin_ptr<unsigned char> strcliPtr = &StrBytes[0];

						 unsigned char* dsc = new unsigned char[StrBytes->Length];

						 memcpy(dsc, strcliPtr, StrBytes->Length);



						 int lengt = StrBytes->Length;

						 if (lengt >= MAXSTR)
							 lengt = MAXSTR;

						 int lengt2 = lengt * 2;
						 if (lengt2 >= MAXSTR)
							 lengt2 = MAXSTR;


						 win->SetMsg("正在查找..请勿操作代码窗口");
						 

						 ea_t minaddress = inf.minEA;
						 ea_t maxaddress = inf.maxEA;

						 for (ea_t i = minaddress; i < maxaddress && win->IsFind; i++)
						 {
							 flags_t flag = getFlags(i);


							 if (!isTail(flag) || win->checkBox1->Checked)
							 {

								 unsigned char * txt = new  unsigned char[lengt2];

								 if (get_many_bytes(i, txt, lengt2))
								 {

									 if (FindCmp(dsc, txt, lengt))
									 {
										 array<System::Byte> ^bytes = gcnew array<System::Byte>(MAXSTR);

										 System::Runtime::InteropServices::Marshal::Copy((IntPtr)txt, bytes, 0, MAXSTR);


										 FindEa^ var1 = gcnew FindEa();
										 var1->TextLen=Convert::ToString(MAXSTR);
										 if (win->checkBox2->Checked)
											 var1->Text = win->Code->Unicode->GetString(bytes);
										 else
											var1->Text = win->Code->GetString(bytes);
										 var1->Address = i;
										 var1->CodeHex=hextostr(bytes);
										 var1->IsRef = hasRef(flag);
										 win->InsertFindContext(var1);

										 if (!win->checkBox1->Checked)
											 i += StrBytes->Length;

									 }
								 }


								 delete txt;

							 }

							 if (i % 1000 == 0)
							 {
								 win->SetProcessValue(i-minaddress);
							 }

						 }

						 win->SetProcessValue(maxaddress-minaddress);

						 win->SetBouttionStop();

						 if (win->listView1->Items->Count == 0)
						 {
							 win->SetMsg("查找结束，共查找到:0 个结果");
							 MessageBox::Show("没有找到该字符串");
							
						 }
						 else
						 {
							
							 win->SetMsg("查找结束，共查找到:" + win->listView1->Items->Count + " 个结果");

						 }

					
						 delete dsc;

					 }
				 }
				 catch (System::Exception ^ er)
				 {
					 MessageBox::Show(er->ToString());
				 }
	}

private: static int UtoA(array<System::Byte> ^pbytes,int *plen)
{
	int i=0;
	int j=-1;
	for(i=0;i<*plen;i++)
	{
		if (pbytes[i]!=0)
		{
			j++;
			if(i!=j)
				pbytes[j]=pbytes[i];
			
		}
		
			
	}
	if(j<*plen-1)
		pbytes[j+1]=0;
	*plen=j;
	return j;
}

private: static int chgx(array<System::Byte> ^pbytes,int *plen)
		 {
			 int i=0;
			 int j;
			 for(i=0;i<*plen-1;i++)
			 {
				 if (pbytes[i]>122 || pbytes[i+1]>122 || pbytes[i]<48 || pbytes[i+1]<48 )
				 {
					 j=pbytes[i];
					 pbytes[i]=pbytes[i+1];
					 pbytes[i+1]=j;
					 i++;
				 }
			 }
			 return 1;
		 }

private: System::String^ strtohex(System::String^ pstr){
			 Encoding^ Code;
			 Code = Encoding::Default;
			 array<unsigned char> ^bytvalue;
			 if(checkBox3->Checked)
				 bytvalue=Code->UTF8->GetBytes(pstr );
			 else if (checkBox2->Checked)
				 bytvalue=Code->Unicode->GetBytes(pstr );
			 else
				 bytvalue = Code->GetBytes(pstr);
			 System::String^ strret;
			 System::String^ strtmp;
			 //strret=&bytvalue[0
			 strret="";
			 for(int i=0;i<bytvalue->Length;i++){
				 strtmp="00"+Convert::ToString((int)bytvalue[i], 16);
				 strret+= strtmp->Substring(strtmp->Length-2,2)+" ";
			 }

		return  strret->TrimEnd();
	}

		 private: System::String^ hextounicode(System::String^ pstr)
				  {
					  Encoding^ Code;
					  Code = Encoding::Default;
					  System::String^ strtmp;
					  System::String^ strret;
					  strtmp=pstr->Replace(" ","");
					  strtmp=strtmp->Replace("\r","");
					  strtmp=strtmp->Replace("\n","");
					  int ilen=strtmp->Length /2;  //
					  array<unsigned char> ^bytret = gcnew array<unsigned char>(ilen);
					  for(int i=0;i<ilen;i++)
					  {
						  //bytret[i]=(char)Convert::ToInt32( strtmp[i],16);
						  bytret[i]=(char) Convert::ToInt32( strtmp->Substring(i*2,2),16);
					  }
					  if(checkBox3->Checked)
						  strret=Code->UTF8->GetString(bytret);
					  else if (checkBox2->Checked)
						  strret=Code->Unicode->GetString(bytret);
					  else
						  strret = Code->GetString(bytret);
					  return  strret;
				  }

		private: System::String^ hextounicode(System::String^ pstr,int ptype)
				 {
					 Encoding^ Code;
					 Code = Encoding::Default;
					 System::String^ strtmp;
					 System::String^ strret;
					 strtmp=pstr->Replace(" ","");
					 strtmp=strtmp->Replace("\r","");
					 strtmp=strtmp->Replace("\n","");
					 int ilen=strtmp->Length /2;  //
					 array<unsigned char> ^bytret = gcnew array<unsigned char>(ilen);
					 for(int i=0;i<ilen;i++)
					 {
						 //bytret[i]=(char)Convert::ToInt32( strtmp[i],16);
						 bytret[i]=(char) Convert::ToInt32( strtmp->Substring(i*2,2),16);
					 }
					 if(ptype==2)
						 strret=Code->UTF8->GetString(bytret);
					 else if (ptype==1)
						 strret=Code->Unicode->GetString(bytret);
					 else
						 strret = Code->GetString(bytret);
					 return  strret;
				 }
private:static System::String^ hextostr(array<System::Byte> ^pbytes)
		{
			System::String ^strret;
			System::String ^strtmp;
			for(int i=0;i<pbytes->Length;i++){
				strtmp="00"+Convert::ToString((int)pbytes[i], 16);
				strret+=strtmp->Substring(strtmp->Length-2,2)+" ";
			}
			return strret->Trim();
		}

private:static	int checkzero(array<System::Byte> ^pbytes,int pstrlen)
		{
			//unsigned char* p=scr;
			for(int i=0;i<pstrlen;i++){
				if(pbytes[i]==0 )
					return 1;
				//p++;
			}
			return 0;
		}


private: static Void FindStrRunAll(Object^ send)
	{
				 try
				 {
					 FindStr^ win = dynamic_cast<FindStr^>(send);
					 
					 if (win != nullptr)
					 {

						 /*if (String::IsNullOrEmpty(win->richTextBox1->Text))
						 {
							 MessageBox::Show("请输入字符串");
							 return;
						 }



						 array<unsigned char> ^StrBytes = win->Code->GetBytes(win->richTextBox1->Text);

						 cli::pin_ptr<unsigned char> strcliPtr = &StrBytes[0];

						 unsigned char* dsc = new unsigned char[StrBytes->Length];

						 memcpy(dsc, strcliPtr, StrBytes->Length);
						 int lengt = StrBytes->Length;

*/
						 //字符串长度定义
						 int lengt = 1024;

						 if (lengt >= MAXSTR)
							 lengt = MAXSTR;

						 /*int lengt2 = lengt * 2;
						 if (lengt2 >= MAXSTR)
							 lengt2 = MAXSTR;*/


						 win->SetMsg("正在查找..请勿操作代码窗口");
						 

						 /*ea_t minaddress = inf.minEA;
						 ea_t maxaddress = inf.maxEA;*/
						 ea_t minaddress = win->mminaddress;
						 ea_t maxaddress = win->mmaxaddress;
						 int iproc=0;
						 int lcount;
						 int llen;
						 llen=Convert::ToInt32(win->textBox2->Text);
						 ea_t i;
						 lcount=0;
						 for (i = minaddress; i < maxaddress && win->IsFind; i++)
						 {
							 flags_t flag = getFlags(i);

							 
							 if (!isTail(flag) || win->checkBox1->Checked)
							 {
								 if ((int)(maxaddress-i)<lengt)
									 lengt=maxaddress-i;
								 unsigned char * txt = new  unsigned char[lengt];

								 if (get_many_bytes(i, txt, lengt))
								 {
									 int lstrlen=0;
									 int llastpos=0;
									 int lpos=-1;
									 int lisunicode=0;
									 if (!win->checkBox2->Checked && !win->checkBox3->Checked){
										 lpos=FindAscii(txt, lengt,llen,&lstrlen,&lisunicode);
										 //防止字符串不完整
										if(lpos>=0 && lpos+lstrlen>=lengt){
											llastpos=lpos;
											lpos=-1;
										}
										 //win->SetMsg(""+*txt+*(txt+1)+*(txt+2)+*(txt+3));
										win->SetMsg(i+":"+lpos+":"+lstrlen+":"+lengt);
										 while(lpos>=0)
										 {
											 llastpos=0;
											 array<System::Byte> ^bytes = gcnew array<System::Byte>(lstrlen);
											 
											 System::Runtime::InteropServices::Marshal::Copy((IntPtr)(txt+lpos), bytes, 0, lstrlen);

											 //lock(win->listView1);
												/*win->mfindea[win->mThreadID,lcount]->Text = win->Code->GetString(bytes);
												win->mfindea[win->mThreadID,lcount]->Address = i+lpos;
												win->mfindea[win->mThreadID,lcount]->IsRef = hasRef(flag);*/
											 /*if(win->chkios->Checked)
												chgx(bytes,&lstrlen);*/
											 int iszero=0;
											 if (win->checkBox4->Checked && lstrlen>=4 && lstrlen<=5 ){
												 iszero=checkzero(bytes,lstrlen);
											 }
											 else
												 iszero=0;

											 if (iszero==0){
												 FindEa^ var1 = gcnew FindEa();
												 var1->TextLen=Convert::ToString(lstrlen);
												 if (!lisunicode || !win->chkios->Checked)
													 var1->Text = win->Code->GetString(bytes);
												 else
													 var1->Text = win->Code->Unicode->GetString(bytes);
												 var1->Address = i+lpos;
												 var1->CodeHex=hextostr(bytes);
												 var1->IsRef = hasRef(flag);
												 win->InsertFindContext(var1);
												 
													 //lcount++;
													 //if(lcount>=10000)
													//	 break;
													 win->mlstcount++;
											 }
											 /*if (!win->checkBox1->Checked)
												 i += StrBytes->Length;*/
											 lpos=lpos+lstrlen+1;
											 llastpos=lpos;
											 lpos=FindAsciiNext(txt, lengt,llen,lpos,&lstrlen,&lisunicode);
											 //防止字符串不完整
											 if(lpos>=0 && lpos+lstrlen>=lengt){
												 llastpos=lpos;
												 lpos=-1;
											 }
										 }
									 }else if(win->checkBox2->Checked){
										 //搜索中文
										 lpos=FindAsciiU(txt, lengt,llen,&lstrlen);
										 //防止字符串不完整
										if(lpos>=0 && lpos+lstrlen>=lengt){
											llastpos=lpos;
											lpos=-1;
										}
										 //win->SetMsg(""+*txt+*(txt+1)+*(txt+2)+*(txt+3));
										win->SetMsg(i+":"+lpos+":"+lstrlen+":"+lengt);
										 while(lpos>=0)
										 {
											 llastpos=0;
											 array<System::Byte> ^bytes = gcnew array<System::Byte>(lstrlen);
											 
											 System::Runtime::InteropServices::Marshal::Copy((IntPtr)(txt+lpos), bytes, 0, lstrlen);

											 int ilen=lstrlen;
											 //UtoA(bytes,&ilen);
											 /*if(win->chkios->Checked)
												 chgx(bytes,&ilen);*/
											 //lock (win->listView1){
												 FindEa^ var1 = gcnew FindEa();
												 var1->TextLen=Convert::ToString(lstrlen);
												 var1->Text = win->Code->Unicode->GetString(bytes);
												 var1->Address = i+lpos;
												 var1->CodeHex=hextostr(bytes);
												 var1->IsRef = hasRef(flag);
												 win->InsertFindContext(var1);
												 //win->mfindea[win->mThreadID,lcount]=var1;
												 //lcount++;
												 //if(lcount>=10000)
												//	 break;
												 win->mlstcount++;
											 //}
											 /*if (!win->checkBox1->Checked)
												 i += StrBytes->Length;*/
											 lpos=lpos+lstrlen+1;
											 llastpos=lpos;
											 lpos=FindAsciiNextU(txt, lengt,llen,lpos,&lstrlen);
											 //防止字符串不完整
											 if(lpos>=0 && lpos+lstrlen>=lengt){
												 llastpos=lpos;
												 lpos=-1;
											 }
										 }
									}else{
										 //搜索中文
										 lpos=FindAsciiUtf8(txt, lengt,llen,&lstrlen);
										 //防止字符串不完整
										if(lpos>=0 && lpos+lstrlen>=lengt){
											llastpos=lpos;
											lpos=-1;
										}
										 //win->SetMsg(""+*txt+*(txt+1)+*(txt+2)+*(txt+3));
										win->SetMsg(i+":"+lpos+":"+lstrlen+":"+lengt);
										 while(lpos>=0)
										 {
											 llastpos=0;
											 array<System::Byte> ^bytes = gcnew array<System::Byte>(lstrlen);
											 
											 System::Runtime::InteropServices::Marshal::Copy((IntPtr)(txt+lpos), bytes, 0, lstrlen);

											 //lock(win->listView1){
												 FindEa^ var1 = gcnew FindEa();
												 var1->TextLen=Convert::ToString(lstrlen);
												 win->Code->GetString(bytes);
												 String^ sstr=win->Code->UTF8->GetString(bytes);
												 if(lstrlen/2>sstr->Length)
													 sstr=win->Code->Unicode->GetString(bytes);
												 var1->Text = sstr;
												 var1->Address = i+lpos;
												 var1->CodeHex=hextostr(bytes);
												 var1->IsRef = hasRef(flag);
												 win->InsertFindContext(var1);
												 //win->mfindea[win->mThreadID,lcount]=var1;
												 //lcount++;
												 //if(lcount>=10000)
												//	 break;
												 win->mlstcount++;
											 //}
											 /*if (!win->checkBox1->Checked)
												 i += StrBytes->Length;*/
											 lpos=lpos+lstrlen+1;
											 llastpos=lpos;
											 lpos=FindAsciiNextUtf8(txt, lengt,llen,lpos,&lstrlen);
											 //防止字符串不完整
											 if(lpos>=0 && lpos+lstrlen>=lengt){
												 llastpos=lpos;
												 lpos=-1;
											 }
										 }
									} //else
									 i += llastpos;
								 }
								 delete txt;
								 
							 }//if (!isTail(flag) || win->checkBox1->Checked)
							 iproc++;
							 if ((i % 1000 == 0) || (iproc % 20==0))
							 {
								 iproc=0;
								 win->SetProcessValue(i-minaddress);
							 }
							 //if (lcount >=10000)
							//	 break;
						 }//for

						 win->SetProcessValue(i-minaddress);
						 //win->SetProcessValue(maxaddress-minaddress);

						 win->SetButton2Stop();

						 //if (win->listView1->Items->Count == 0)
						 if(win->mlstcount==0)
						 {
							 win->SetMsg("查找结束，共查找到:0 个结果");
							 //MessageBox::Show("没有找到该字符串");
							
						 }
						 else
						 {
							
							 win->SetMsg("查找结束，共查找到:" + win->mlstcount + " 个结果");

						 }

					 }
				 }
				 catch (System::Exception ^ er)
				 {
					 MessageBox::Show(er->ToString());
					 //win->SetMsg(er->ToString());
				 }
	}

	public:void SetProcessValue(int var)
	{
			   this->BeginInvoke(gcnew System::EventHandler(this, &FindStr::_SetProcessValue), var);
	}


	private: void _SetProcessValue(System::Object^  sender, System::EventArgs^  e)
	{
				 int var = (int)sender;
				 this->label3->Text = Convert::ToString((int)(var + inf.minEA), 16) + "/" + Convert::ToString((int)inf.maxEA, 16);
				 this->label3->Invalidate();
				 this->progressBar1->Value = var;
				 this->progressBar1->Invalidate();
	}


	public:void SetBouttionStop()
	{
			   this->BeginInvoke(gcnew System::EventHandler(this, &FindStr::SetBouttionFalse));
	}

	private: void SetBouttionFalse(System::Object^  sender, System::EventArgs^  e)
	{
				 IsFind = false;
				 this->button1->Text = "查找";
	}

public:void SetButton2Stop()
	{
			   this->BeginInvoke(gcnew System::EventHandler(this, &FindStr::SetButton2False));
	}

	private: void SetButton2False(System::Object^  sender, System::EventArgs^  e)
	{
				 IsFind = false;
				 this->button2->Text = "查找所有";
	}

	public:void SetMsg(String^ msg)
	{
			   this->BeginInvoke(gcnew System::EventHandler(this, &FindStr::SetLableText), msg);
	}

	private: void SetLableText(System::Object^  sender, System::EventArgs^  e)
	{
				 String^ msg = dynamic_cast<String^>(sender);

				 this->label2->Text = msg;
				 this->label2->Invalidate();
				 this->label2->Update();
	}


	public:void InsertFindContext(FindEa^ obj)
	{
			   this->BeginInvoke(gcnew System::EventHandler(this, &FindStr::SetList), obj);
	}

	
	private:System::Void SetList(System::Object^  sender, System::EventArgs^  e)
	{
		try
		{
				FindEa^ var = dynamic_cast<FindEa^>(sender);

				if (var != nullptr)
				{
					System::Windows::Forms::ListViewItem ^temp = gcnew System::Windows::Forms::ListViewItem("0x" + Convert::ToString((int)var->Address, 16));
					temp->Tag = var;

					System::Windows::Forms::ListViewItem::ListViewSubItem ^Sub3 = gcnew System::Windows::Forms::ListViewItem::ListViewSubItem();
					Sub3->Text = var->TextLen;
					temp->SubItems->Add(Sub3);

					System::Windows::Forms::ListViewItem::ListViewSubItem ^Sub1 = gcnew System::Windows::Forms::ListViewItem::ListViewSubItem();
					Sub1->Text = var->Text;
					temp->SubItems->Add(Sub1);

					System::Windows::Forms::ListViewItem::ListViewSubItem ^Sub4 = gcnew System::Windows::Forms::ListViewItem::ListViewSubItem();
					Sub4->Text = var->CodeHex;
					temp->SubItems->Add(Sub4);

					System::Windows::Forms::ListViewItem::ListViewSubItem ^Sub2 = gcnew System::Windows::Forms::ListViewItem::ListViewSubItem();
					Sub2->Text = (var->IsRef == true ? "是" : "否");
					temp->SubItems->Add(Sub2);

					this->listView1->Items->Add(temp);
				}
			}
			catch (System::Exception ^ er)
			{
				//MessageBox::Show(er->ToString());
				this->SetMsg(er->ToString());
			}
	}


	private: System::Void FindStr_Load(System::Object^  sender, System::EventArgs^  e) {

				 this->comboBox1->Items->Add(Encoding::Default);
				 this->comboBox1->Items->Add(Encoding::ASCII);			
				 this->comboBox1->Items->Add(Encoding::Unicode);
				 this->comboBox1->Items->Add(Encoding::UTF32);
				 this->comboBox1->Items->Add(Encoding::UTF8);
				 this->comboBox1->Items->Add(Encoding::UTF7);
				 this->comboBox1->SelectedItem = Encoding::Default;
				 Code = Encoding::Default;
				 CodeUnicode= Encoding::Unicode;

				 SetWindowPos(this->Handle ,-2,0,0,0,0,3);
	}

	private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
	{
				 Code = (Encoding^)this->comboBox1->SelectedItem;
	}
private: System::Void 复制地址ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
{
			 if (this->listView1->SelectedItems->Count > 0)
			 {
				 FindEa^ tmp = dynamic_cast<FindEa^>(this->listView1->SelectedItems[0]->Tag);

				 if (tmp!=nullptr)
					Clipboard::SetDataObject("0x" + Convert::ToString((int)tmp->Address,16), true);
			 }
}
private: System::Void 添加到注释ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
{
			 if (this->listView1->SelectedItems->Count > 0)
			 {
				 FindEa^ tmp = dynamic_cast<FindEa^>(this->listView1->SelectedItems[0]->Tag);

				 if (tmp != nullptr)
				 {
					 char* result = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(tmp->Text);
					 

					 set_cmt(tmp->Address, result, true);
				 }
			 }
}
private: System::Void listView1_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
{
			 FindEa^ tmp = dynamic_cast<FindEa^>(this->listView1->SelectedItems[0]->Tag);

			 if (tmp != nullptr)
			 {
				 jumpto(tmp->Address);

			 }
}
private: System::Void richTextBox1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	/*if(e->Button == MouseButtons.Right)
	{
		this->richTextBox1->ContextMenu = this->contextMenuStrip2;
	}*/


}

private: System::Void MenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->richTextBox1->Copy();
		 }

private: System::Void MenuItem2_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->richTextBox1->Paste();
		 }

private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			if (!IsFind)
			{
				IsFind = true;
				this->listView1->Items->Clear();
				this->button2->Text = "停止";

				/*mfindea=gcnew array<FindEa^,2>(10,10000);

				int addrvalue=inf.maxEA-inf.minEA;
				int addragv=addrvalue /10;
				this->progressBar1->Maximum = addragv+1;
				this->progressBar1->Value = 0;
				int ithread;
				Threading::ThreadPool::SetMinThreads(1,1);
				Threading::ThreadPool::SetMaxThreads(10,10);
				for (ithread=0;ithread<10;ithread++){
					this->mThreadID=ithread;
					this->mminaddress=inf.minEA+ithread*addragv;
					this->mmaxaddress=inf.minEA+(ithread+1)*addragv;
					mlstcount=0;
					
					Threading::ThreadPool::QueueUserWorkItem(gcnew Threading::WaitCallback(FindStrRunAll), this);
				}
				
				for(int v1=0;v1<10;v1++){
					for(int v2=0;v2<10000;v2++){
						if(mfindea[v1,v2]!=nullptr)
							this->InsertFindContext(mfindea[v1,v2]);
						else
							break;
					}
				}
				if (this->listView1->Items->Count == 0)
				{
					this->SetMsg("查找结束，共查找到:0 个结果");
					//MessageBox::Show("没有找到该字符串");

				}
				else
				{

					this->SetMsg("查找结束，共查找到:" + this->listView1->Items->Count  + " 个结果");

				}*/
				this->mminaddress=inf.minEA;
				this->mmaxaddress=inf.maxEA;
				this->progressBar1->Maximum = mmaxaddress-mminaddress;
				this->progressBar1->Value = 0;
				mlstcount=0;
				Threading::ThreadPool::QueueUserWorkItem(gcnew Threading::WaitCallback(FindStrRunAll), this);
						//FindStrRunAll(this);
				//
			}
			else
			{
				IsFind = false;
				this->button2->Text = "查找所有";

			}
		 }

int findlist(System::String ^pstr,int ppos)
{
	System::String ^strtmp;
	for(int i=ppos;i<listView1->Items->Count;i++)
	{
		//FindEa^ tmp = dynamic_cast<FindEa^>listView1->Items[i]->Tag;
		if (chkHexFind->Checked){
			pstr=pstr->ToLower();
			strtmp=listView1->Items[i]->SubItems[3]->Text;
		}
		else
			strtmp=listView1->Items[i]->SubItems[2]->Text;
		if (strtmp->IndexOf(pstr)>=0)
			return i;
	}
	return -1;
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		if (listView1->Items->Count==0) 
			return;

		if (chkfind->Checked){
			mlstindex=findlist(textBox1->Text,0);
			if (mlstindex>=0)
				listView1->TopItem=listView1->Items[mlstindex];
			else
				MessageBox::Show(this, "没有找到！");
		}else{
			ListViewItem^ foundItem =listView1->FindItemWithText(textBox1->Text, 1, 0, true);
			if (foundItem != nullptr)
			{
				listView1->TopItem = foundItem;
				mlstindex=foundItem->Index;
			}
			else
				MessageBox::Show(this, "没有找到！");
		}
		 }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (listView1->Items->Count==0) 
				 return;
			 if (chkfind->Checked){
				 mlstindex=findlist(textBox1->Text,mlstindex+1);
				 if (mlstindex>=0)
					listView1->TopItem=listView1->Items[mlstindex];
				 else
					 MessageBox::Show(this, "已经到最后一个！");
			 }else{
				 ListViewItem^ foundItem =listView1->FindItemWithText(textBox1->Text, 1, mlstindex+1, true);
				 if (foundItem != nullptr)
				 {
					 listView1->TopItem = foundItem;
					 mlstindex=foundItem->Index;
				 }
				 else
					 MessageBox::Show(this, "已经到最后一个！");
			 }
		 }
private: System::Void 复制内容ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (this->listView1->SelectedItems->Count > 0)
			 {
				 FindEa^ tmp = dynamic_cast<FindEa^>(this->listView1->SelectedItems[0]->Tag);

				 if (tmp!=nullptr)
					 Clipboard::SetDataObject(tmp->Text, true);
			 }
		 }
private: System::Void 复制十六进制ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (this->listView1->SelectedItems->Count > 0)
			 {
				 FindEa^ tmp = dynamic_cast<FindEa^>(this->listView1->SelectedItems[0]->Tag);

				 if (tmp!=nullptr)
					 Clipboard::SetDataObject(tmp->CodeHex, true);
			 }
		 }
private: System::Void chktop_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (chktop->Checked)
				 //SetWindowPos((HWND)this->Handle.ToInt32() ,HWND_TOPMOST,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE);
				 SetWindowPos(this->Handle ,-1,0,0,0,0,3);
			 else
				 SetWindowPos(this->Handle,-2,0,0,0,0,3);
		 }
private: System::Void 转十六进制ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 try{
				 System::String^ strtmp=richTextBox1->Text;
				 textBox1->Text=strtohex(strtmp);
			 }
			 catch (System::Exception ^ er)
			 {
				 MessageBox::Show(er->ToString());
			 }
		 }
private: System::Void 转UnicodeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 try{
				 System::String^ strtmp=richTextBox1->Text;
				 textBox1->Text=hextounicode(strtmp);
			 }
			 catch (System::Exception ^ er)
			 {
				 MessageBox::Show(er->ToString());
			 }
		 }
private: System::Void unicodeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 
			 
				 if (this->listView1->SelectedItems->Count > 0)
				 {
					 FindEa^ tmp = dynamic_cast<FindEa^>(this->listView1->SelectedItems[0]->Tag);
					//System::Windows::Forms::ListViewItem ^tempitem=(System::Windows::Forms::ListViewItem ^)this->listView1->SelectedItems[0];
					 if (tmp!=nullptr){
						System::String^ strtmp=tmp->CodeHex;
						int llen=strtmp->Length;
						System::String^ str=strtmp->Substring(3,llen-3);
						tmp->Text= hextounicode(str,1);
						//tempitem->Tag=tmp;
						//System::Windows::Forms::ListViewItem::ListViewSubItem ^Sub2 = gcnew System::Windows::Forms::ListViewItem::ListViewSubItem();
						//Sub2->Text = tmp->Text;
						//tempitem->SubItems[2]=Sub2;
						this->listView1->SelectedItems[0]->SubItems[2]->Text=tmp->Text;
						this->listView1->SelectedItems[0]->Tag=tmp;
						 
					 }
				 }
		 }
private: System::Void ansiToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (this->listView1->SelectedItems->Count > 0)
			 {
				 FindEa^ tmp = dynamic_cast<FindEa^>(this->listView1->SelectedItems[0]->Tag);
				 //System::Windows::Forms::ListViewItem ^tempitem=(System::Windows::Forms::ListViewItem ^)this->listView1->SelectedItems[0];
				 if (tmp!=nullptr){
					 System::String^ strtmp=tmp->CodeHex;
					 tmp->Text= hextounicode(strtmp,0);
					 //tempitem->Tag=tmp;
					 //System::Windows::Forms::ListViewItem::ListViewSubItem ^Sub2 = gcnew System::Windows::Forms::ListViewItem::ListViewSubItem();
					 //Sub2->Text = tmp->Text;
					 //tempitem->SubItems[2]=Sub2;
					 this->listView1->SelectedItems[0]->SubItems[2]->Text=tmp->Text;
					 this->listView1->SelectedItems[0]->Tag=tmp;

				 }
			 }
		 }
private: System::Void unicodeToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (this->listView1->SelectedItems->Count > 0)
			 {
				 FindEa^ tmp = dynamic_cast<FindEa^>(this->listView1->SelectedItems[0]->Tag);
				 //System::Windows::Forms::ListViewItem ^tempitem=(System::Windows::Forms::ListViewItem ^)this->listView1->SelectedItems[0];
				 if (tmp!=nullptr){
					 System::String^ strtmp=tmp->CodeHex;
					 tmp->Text= hextounicode(strtmp,1);
					 this->listView1->SelectedItems[0]->SubItems[2]->Text=tmp->Text;
					 this->listView1->SelectedItems[0]->Tag=tmp;

				 }
			 }
		 }
private: System::Void uTF8ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (this->listView1->SelectedItems->Count > 0)
			 {
				 FindEa^ tmp = dynamic_cast<FindEa^>(this->listView1->SelectedItems[0]->Tag);
				 //System::Windows::Forms::ListViewItem ^tempitem=(System::Windows::Forms::ListViewItem ^)this->listView1->SelectedItems[0];
				 if (tmp!=nullptr){
					 System::String^ strtmp=tmp->CodeHex;
					 tmp->Text= hextounicode(strtmp,2);
					 this->listView1->SelectedItems[0]->SubItems[2]->Text=tmp->Text;
					 this->listView1->SelectedItems[0]->Tag=tmp;

				 }
			 }
		 }
private: System::Void ansi去掉前两位ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (this->listView1->SelectedItems->Count > 0)
			 {
				 FindEa^ tmp = dynamic_cast<FindEa^>(this->listView1->SelectedItems[0]->Tag);
				 //System::Windows::Forms::ListViewItem ^tempitem=(System::Windows::Forms::ListViewItem ^)this->listView1->SelectedItems[0];
				 if (tmp!=nullptr){
					 System::String^ strtmp=tmp->CodeHex;
					 int llen=strtmp->Length;
					 System::String^ str=strtmp->Substring(6,llen-6);
					 tmp->Text= hextounicode(str,0);
					 //tempitem->Tag=tmp;
					 //System::Windows::Forms::ListViewItem::ListViewSubItem ^Sub2 = gcnew System::Windows::Forms::ListViewItem::ListViewSubItem();
					 //Sub2->Text = tmp->Text;
					 //tempitem->SubItems[2]=Sub2;
					 this->listView1->SelectedItems[0]->SubItems[2]->Text=tmp->Text;
					 this->listView1->SelectedItems[0]->Tag=tmp;

				 }
			 }
		 }
};
}
