%%

COLMAP=zeros(256,3);

COLMAP(1:64,3)=round(255*[0:63]/63)';
COLMAP(64+[1:64],3)=255;
COLMAP(128+[1:64],3)=round(255*[63:-1:0]/63)';

COLMAP(64+[1:64],2)=round(255*[0:63]/63)';
COLMAP(128+[1:64],2)=255;
COLMAP(192+[1:64],2)=round(255*[63:-1:0]/63)';

COLMAP(128+[1:64],1)=round(255*[0:63]/63)';
COLMAP(192+[1:64],1)=255;


plot(0:255,COLMAP(:,1)','r-^',0:255,COLMAP(:,2)','g-s',0:255,COLMAP(:,3)','b-o')

legend('Red','Green','Blue')

saveas(gcf,'colormap_steps.png')

fileID = fopen('colormap_steps.txt','w');
fprintf(fileID,'\tconst unsigned char Steps[256][3]=\n');
fprintf(fileID,'\t{\n');
for II=1:256
    fprintf(fileID,'\t\t{%3d,%3d,%3d}',COLMAP(II,1),COLMAP(II,2),COLMAP(II,3));
    if(II==256)
        fprintf(fileID,'\n');
    else
        fprintf(fileID,',\n');
    endif
endfor
fprintf(fileID,'\t};\n');
fclose(fileID);
