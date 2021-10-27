#include "CuaSoChinh.h"
#include "ChuyenDoi.h"

CuaSoChinh::CuaSoChinh() : QMainWindow(nullptr)
{
    ktGiaoDien();
    ktMenuBar();
    ktToolBar();
    ktStatusBar();

    setWindowTitle(tr("Công cụ chuyển đổi đơn vị"));
    setWindowIcon(QIcon("C:\\Users\\tranq\\Downloads\\Code\\Qt\\ChuyenDoi\\logoAppChuyenDoi.ico"));
    setMinimumWidth(500);
    setMaximumHeight(118);
}

CuaSoChinh::~CuaSoChinh()
{
    //Thuoc tinh giao dien
    delete m_nhanInput;
    delete m_nhanOutput;
    delete m_input;
    delete m_output;
    delete m_chuyenDoi;
    delete m_xoa;
}

//Cac ham khoi tao giao dien
void CuaSoChinh::ktGiaoDien()
{
    m_nhanInput = new QLabel("inch");
    m_input = new QLineEdit();
    m_nhanOutput = new QLabel("cm");
    m_output = new QLineEdit();
    m_output->setReadOnly(true);
    m_chuyenDoi = new QPushButton(tr("Chuyển đổi"));
    m_xoa = new QPushButton(tr("Xóa"));

    QWidget *giaoDien = new QWidget();

    QHBoxLayout *layoutNut = new QHBoxLayout();
        layoutNut->addWidget(m_chuyenDoi);
        layoutNut->addWidget(m_xoa);

    QFormLayout *layoutInput = new QFormLayout();
        layoutInput->addRow(m_nhanInput, m_input);

    QFormLayout *layoutOutput = new QFormLayout();
        layoutOutput->addRow(m_nhanOutput, m_output);

    QVBoxLayout *layoutChinh = new QVBoxLayout();
        layoutChinh->addLayout(layoutInput);
        layoutChinh->addLayout(layoutNut);
        layoutChinh->addLayout(layoutOutput);

    giaoDien->setLayout(layoutChinh);
    setCentralWidget(giaoDien);

    connect(m_chuyenDoi, SIGNAL(clicked()), this, SLOT(chuyenDoi()));
    connect(m_input, SIGNAL(returnPressed()), this, SLOT(chuyenDoi()));
    connect(m_xoa, SIGNAL(clicked()), this, SLOT(xoaTatCa()));
}

void CuaSoChinh::ktMenuBar()
{
    ktMenuChuyenDoi();
}

void CuaSoChinh::ktMenuChuyenDoi()
{
    QMenu *menuChuyenDoi = menuBar()->addMenu(tr("Chuyển đổi"));

    //Do dai
    m_in_to_cm = new QAction("inch -> cm");
        m_in_to_cm->setCheckable(true);
        m_in_to_cm->setChecked(true);
    m_cm_to_in = new QAction("cm -> inch");

    m_modeHienTai = m_in_to_cm;

    QMenu *menuDoDai = menuChuyenDoi->addMenu(tr("Độ dài"));
        menuDoDai->addAction(m_in_to_cm);
        menuDoDai->addAction(m_cm_to_in);

    //Nhiet do
    m_C_to_F = new QAction(tr("°C->°F"));
        m_C_to_F->setCheckable(true);
    m_F_to_C = new QAction(tr("°F->°C"));
        m_F_to_C->setCheckable(true);
    m_C_to_K = new QAction(tr("°C->°K"));
        m_C_to_K->setCheckable(true);
    m_K_to_C = new QAction(tr("°K->°C"));
        m_K_to_C->setCheckable(true);
    m_F_to_K = new QAction(tr("°F->°K"));
        m_F_to_K->setCheckable(true);
    m_K_to_F = new QAction(tr("°K->°F"));
        m_K_to_F->setCheckable(true);

    QMenu *menuNhietDo = menuChuyenDoi->addMenu(tr("Nhiệt độ"));
        menuNhietDo->addAction(m_C_to_F);
        menuNhietDo->addAction(m_F_to_C);
        menuNhietDo->addAction(m_C_to_K);
        menuNhietDo->addAction(m_K_to_C);
        menuNhietDo->addAction(m_F_to_K);
        menuNhietDo->addAction(m_K_to_F);

    connect(m_in_to_cm, SIGNAL(triggered(bool)), this, SLOT(thayDoi_in_to_cm()));
    connect(m_cm_to_in, SIGNAL(triggered(bool)), this, SLOT(thayDoi_cm_to_in()));
    connect(m_C_to_F, SIGNAL(triggered(bool)), this, SLOT(thayDoi_C_to_F()));
    connect(m_F_to_C, SIGNAL(triggered(bool)), this, SLOT(thayDoi_F_to_C()));
    connect(m_C_to_K, SIGNAL(triggered(bool)), this, SLOT(thayDoi_C_to_K()));
    connect(m_K_to_C, SIGNAL(triggered(bool)), this, SLOT(thayDoi_K_to_C()));
    connect(m_F_to_K, SIGNAL(triggered(bool)), this, SLOT(thayDoi_F_to_K()));
    connect(m_K_to_F, SIGNAL(triggered(bool)), this, SLOT(thayDoi_K_to_F()));
}

void CuaSoChinh::ktToolBar()
{

}

void CuaSoChinh::ktStatusBar()
{
    statusBar()->showMessage(tr("Chào mừng"), 3000);
}

void CuaSoChinh::chuyenDoi()
{
    m_input->selectAll();
    m_input->setFocus();

    QString kieu = m_nhanInput->text() + "->" + m_nhanOutput->text();
    double input = m_input->text().toDouble();

    m_output->setText(QString::number(ChuyenDoi(kieu, input)));
}

void CuaSoChinh::xoaTatCa()
{
    m_input->setText("");
    m_input->setFocus();
    m_output->setText("");
}

//Doi nhan
void CuaSoChinh::doiNhan(const QString &nhanInput, const QString &nhanOutput)
{
    m_nhanInput->setText(nhanInput);
    m_nhanOutput->setText(nhanOutput);
}
//Chuyen mode
void CuaSoChinh::chuyenMode(QAction* modeChuyen)
{
    m_modeHienTai->setChecked(false);
    m_modeHienTai = modeChuyen;
    m_modeHienTai->setChecked(true);
}

//Slot xu li chuyen mode
void CuaSoChinh::thayDoi_in_to_cm()
{
    chuyenMode(m_in_to_cm);
    doiNhan("inch", "cm");
}

void CuaSoChinh::thayDoi_cm_to_in()
{
    chuyenMode(m_cm_to_in);
    doiNhan("cm", "inch");
}

void CuaSoChinh::thayDoi_C_to_F()
{
    chuyenMode(m_C_to_F);
    doiNhan("°C", "°F");
}

void CuaSoChinh::thayDoi_F_to_C()
{
    chuyenMode(m_F_to_C);
    doiNhan("°F", "°C");
}

void CuaSoChinh::thayDoi_C_to_K()
{
    chuyenMode(m_C_to_K);
    doiNhan("°C", "K");
}

void CuaSoChinh::thayDoi_K_to_C()
{
    chuyenMode(m_K_to_C);
    doiNhan("K", "°C");
}

void CuaSoChinh::thayDoi_F_to_K()
{
    chuyenMode(m_F_to_K);
    doiNhan("°F", "K");
}

void CuaSoChinh::thayDoi_K_to_F()
{
    chuyenMode(m_K_to_F);
    doiNhan("K", "°F");
}
