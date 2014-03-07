CPP = g++
FLAGS = -Wall -O4
FLAGS += -g
INCS = -I./
LIBS = 
OBJS = test.o Factory.o AbstractFactory.o Builder.o \
		Prototype.o Singleton.o Adapter.o Bridge.o \
		Composite.o Decorator.o Proxy.o TemplateMethod.o \
		ChainOfResponsibility.o Flyweight.o Command.o \
		Observer.o Iterator.o Memento.o Visitor.o
TARGET = test

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CPP) -o $(TARGET) $(OBJS) $(LIBS)
%.o: %.cpp
	$(CPP) -o $@ -c $< $(INCS) $(FLAGS)

.PNHONY: clean
clean:
	rm -f $(TARGET)
	rm -f $(OBJS)
