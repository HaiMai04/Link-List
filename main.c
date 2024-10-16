#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct sinh_vien {
    char Ho_ten[20];
    int sbd;
    float diem;
    struct sinh_vien *tiep
} p_sv;
    int co_psv = sizeof(p_sv);
    p_sv *pdau = NULL;

void taods_sinhvien(p_sv**p_dau) {
    p_sv *p;
    char bht[25];
    printf("nhap ho ten sv neu muon kt thi khong nhap ho ten\n");
    *p_dau = NULL;
    do {
        printf("nhap ten sinh vien ");
        fflush(stdin);
        gets(bht);
        if (bht[0] != 0) {
        if (*p_dau == NULL)
        {
            *p_dau = (p_sv*)malloc(co_psv);
            p = *p_dau;
        }
        else {
            p->tiep=(p_sv*)malloc(co_psv);
            p = p->tiep;
            }
            p->tiep = NULL;
            strcpy(p->Ho_ten, bht);
            printf("sbd: ");
            scanf("%d", &p->sbd);
            printf("diem tb");
            scanf("%f", &p->diem);
        }
    }
    while (bht[0] != 0);
    }


void hien_ds(p_sv*p_dau) {
    int i;
    p_sv*p = p_dau;
    printf("            BANG DIEM SINH VIEN\n");
    printf("            ====================\n");
    printf("        STT     HO TEN   SBD   DIEMTB");
    i=0;
    while(p!= NULL) {
        printf("%d      %s      &d      %f", ++i, p->Ho_ten, p->sbd, p->diem);
        p = p->tiep;
    }

}


    int main () {
        int choice;
        scanf("%d", &choice);
        do {
        printf("1. Tao danh sach");
        printf("2. hien thi ds");
        system("cls");
        switch (choice) {
        case 1 : taods_sinhvien(&pdau);
        break;
        case 2 : hien_ds(pdau);
        break;
        default:
            printf("lua chon khong hop le");
        }
            }
        while (choice != 3);
    }


