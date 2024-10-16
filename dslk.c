#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct sinh_vien {
    char ten[20];
    int sbd;
    float diem;
    struct sinh_vien *next
} SinhVien;

SinhVien* p_dau = NULL;

void taods_sinhvien() {
    SinhVien* p_cuoi;
    char ten[25];
    printf("nhap ho ten sv neu muon ket thuc thi khong nhap ho ten\n");
    do {
        printf("nhap ten sinh vien ");
        fflush(stdin);
        gets(ten);
        if (ten[0] != 0) {
            if (p_dau == NULL){
                p_dau = (SinhVien*)malloc(sizeof(SinhVien));
                p_cuoi = p_dau;
            }else {
                p_cuoi->next = (SinhVien*)malloc(sizeof(SinhVien));
                p_cuoi = p_cuoi->next;
            }
            p_cuoi->next = NULL;

            strcpy(p_cuoi->ten, ten);
            printf("sbd: ");
            scanf("%d", &p_cuoi->sbd);
            printf("diem tb");
            scanf("%f", &p_cuoi->diem);
        }
    }while (ten[0] != 0);
}


void hien_ds() {
    int i;
    SinhVien* temp = p_dau;
    printf("            BANG DIEM SINH VIEN\n");
    printf("            ====================\n");
    printf("        STT     HO TEN   SBD   DIEMTB\n");
    i=0;
    while(temp!= NULL) {
        printf("%d      %s      %d      %f\n", ++i, temp->ten, temp->sbd, temp->diem);
        temp = temp->next;
    }
}


int main () {
    int choice;
    do {
        printf("1. Tao danh sach\n");
        printf("2. hien thi ds\n");
        scanf("%d", &choice);
        system("cls");
        switch (choice) {
            case 1 :
                taods_sinhvien();
                break;
            case 2 :
                hien_ds();
                break;
            default:
                printf("lua chon khong hop le");
        }
    }while (choice != 3);
    return 0;
}


