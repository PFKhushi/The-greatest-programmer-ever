from threading import Lock

class Singleton:
    _instance = None
    _lock = Lock()
    
    def __init__(self, data: str):
        self.data = data
    
    @classmethod
    def get_instance(cls, data: str):
        with cls._lock: 
            if cls._instance is None:
                cls._instance = cls(data)
        return cls._instance
    
    def get_data(self) -> str:
        return self.data

singleton1 = Singleton.get_instance("Conteudo unico")
print(f"Primeira criacao de instancia: {singleton1.get_data()}")
    
singleton2 = Singleton.get_instance("Outro conteudo")
print(f"Segunda criacao: {singleton2.get_data()}")
    
print(f"Sao a mesma instancia? {singleton1 is singleton2}")