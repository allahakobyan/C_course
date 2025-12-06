#include <stdio.h>

union SensorData {
	int temperature;
	float pressure;
	float humidity;
};

int main() {
	union SensorData data;
	int type;

	printf("Select sensor type:\n");
	printf("1. Temperature (int)\n");
	printf("2. Pressure (float)\n");
	printf("3. Humidity (float)\n");
	printf("Enter choice: ");
	scanf("%d", &type);

	switch (type) {
		case 1:
		printf("Enter temperature: ");
		scanf("%d", &data.temperature);
		printf("Temperature reading = %d°C\n", data.temperature);
		break;

		case 2:
		printf("Enter pressure: ");
		scanf("%f", &data.pressure);
		printf("Pressure reading = %.2f Pa\n", data.pressure);
		break;

		case 3:
		printf("Enter humidity: ");
		scanf("%f", &data.humidity);
		printf("Humidity reading = %.2f %%\n", data.humidity);
		break;

		default:
		printf("Invalid sensor type.\n");
	}

	return 0;
}
