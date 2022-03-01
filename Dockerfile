FROM ubuntu
ADD ./lab1.sh Desctop/lab1.sh
RUN chmod +x Desctop/lab1.sh
CMD ["Desctop/lab1.sh"]
