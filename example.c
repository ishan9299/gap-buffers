#define GAP_BUFFER_IMPLEMENTATION
#include "gap_buffer.h"
#include <stdio.h>
#include <stdint.h>

#define KILO_BYTES(x) x*1024
#define MEGA_BYTES(x) x*KILO_BYTES(x)

char *loadFile(const char *filePath, size_t *fileSize)
{
    FILE *fp;
    errno_t failed = fopen_s(&fp, filePath, "r");
    if (failed)
    {
        return 0;
    }

    fseek(fp, 0, SEEK_END);
    *fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char *buffer = (char *)malloc((*fileSize)*sizeof(char));
    fread_s(buffer, *fileSize, 1, *fileSize, fp);
    fclose(fp);
    return buffer;
}

int main()
{
    struct GapBuffer gb;
    gapBufferInit(&gb, 3);
    gapBufferInsertChar(&gb, 'a');
    gapBufferInsertChar(&gb, 'b');
    gapBufferInsertChar(&gb, 'c');
    gapBufferInsertChar(&gb, 'd');
    gapBufferInsertChar(&gb, 'e');
    gapBufferInsertChar(&gb, 'f');
    gapBufferInsertChar(&gb, 'g');
    gapBufferInsertChar(&gb, 'h');
    gapBufferDebug(&gb);
    gapBufferBackspaceChar(&gb);
    gapBufferDebug(&gb);
    gapBufferShiftCursorLeft(&gb);
    gapBufferShiftCursorLeft(&gb);
    gapBufferShiftCursorLeft(&gb);
    gapBufferInsertChar(&gb, 'i');
    gapBufferInsertChar(&gb, 'j');
    gapBufferInsertChar(&gb, 'k');
    gapBufferInsertChar(&gb, 'l');
    gapBufferInsertChar(&gb, 'm');
    gapBufferInsertChar(&gb, 'n');
    gapBufferInsertChar(&gb, 'o');
    gapBufferInsertChar(&gb, 'p');
    gapBufferDebug(&gb);

    gapBufferFree(&gb);
}
