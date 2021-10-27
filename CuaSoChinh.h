#ifndef CUASOCHINH_H
#define CUASOCHINH_H

#include <QtWidgets>

class CuaSoChinh : public QMainWindow
{
    Q_OBJECT

public:
    CuaSoChinh();
    ~CuaSoChinh();

private slots:
    void chuyenDoi();
    void xoaTatCa();

    //Slots xu li chuyen mode
    void thayDoi_in_to_cm();
    void thayDoi_cm_to_in();
    void thayDoi_C_to_F();
    void thayDoi_F_to_C();
    void thayDoi_C_to_K();
    void thayDoi_K_to_C();
    void thayDoi_F_to_K();
    void thayDoi_K_to_F();

private:
    //Cac ham khoi tao giao dien
    void ktGiaoDien();
    void ktToolBar();
    void ktMenuBar();
    void ktMenuChuyenDoi();
    void ktStatusBar();


    //Ham doi nhan
    void doiNhan(const QString &nhanInput, const QString &nhanOutput);
    //Ham chuyen mode
    void chuyenMode(QAction* modeChuyen);

    //Thuoc tinh luu mode hien tai cua chuong trinh
    QAction *m_modeHienTai;

    //Thuoc tinh giao dien
    QLabel *m_nhanInput;
    QLabel *m_nhanOutput;
    QLineEdit *m_input;
    QLineEdit *m_output;
    QPushButton *m_chuyenDoi;
    QPushButton *m_xoa;

    //Thuoc tinh menu
    //Menu Chuyen doi
    //Do dai
    QAction *m_in_to_cm;
    QAction *m_cm_to_in;
    //Nhiet do
    QAction *m_C_to_F;
    QAction *m_F_to_C;
    QAction *m_C_to_K;
    QAction *m_K_to_C;
    QAction *m_F_to_K;
    QAction *m_K_to_F;
};


#endif // CUASOCHINH_H
